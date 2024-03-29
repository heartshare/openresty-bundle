/*
 * Copyright 2010 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Author: jmarantz@google.com (Joshua Marantz)
//     and sligocki@google.com (Shawn Ligocki)

#ifndef NET_INSTAWEB_REWRITER_PUBLIC_SERVER_CONTEXT_H_
#define NET_INSTAWEB_REWRITER_PUBLIC_SERVER_CONTEXT_H_

#include <cstddef>                     // for size_t
#include <set>
#include <utility>
#include <vector>

#include "net/instaweb/http/public/http_cache.h"
#include "net/instaweb/http/public/request_context.h"
#include "net/instaweb/rewriter/public/output_resource.h"
#include "net/instaweb/rewriter/public/resource.h"
#include "net/instaweb/util/public/atomic_bool.h"
#include "net/instaweb/util/public/basictypes.h"
#include "net/instaweb/util/public/md5_hasher.h"
#include "net/instaweb/util/public/property_cache.h"
#include "net/instaweb/util/public/queued_worker_pool.h"
#include "net/instaweb/util/public/ref_counted_ptr.h"
#include "net/instaweb/util/public/scoped_ptr.h"
#include "net/instaweb/util/public/string.h"
#include "net/instaweb/util/public/string_util.h"
#include "pagespeed/kernel/util/simple_random.h"

namespace pagespeed { namespace js { struct JsTokenizerPatterns; } }

namespace net_instaweb {

class AbstractMutex;
class AsyncFetch;
class CacheHtmlInfoFinder;
class CacheInterface;
class CachePropertyStore;
class CriticalCssFinder;
class CriticalImagesFinder;
class CriticalLineInfoFinder;
class CriticalSelectorFinder;
class RequestProperties;
class ExperimentMatcher;
class FileSystem;
class FlushEarlyInfoFinder;
class Function;
class GoogleUrl;
class Hasher;
class MessageHandler;
class NamedLock;
class NamedLockManager;
class PropertyStore;
class RequestHeaders;
class ResponseHeaders;
class RewriteDriver;
class RewriteDriverFactory;
class RewriteDriverPool;
class RewriteFilter;
class RewriteOptions;
class RewriteOptionsManager;
class RewriteQuery;
class RewriteStats;
class Scheduler;
class StaticAssetManager;
class Statistics;
class ThreadSynchronizer;
class ThreadSystem;
class Timer;
class UrlAsyncFetcher;
class UrlNamer;
class UsageDataReporter;
class UserAgentMatcher;
struct ContentType;

typedef RefCountedPtr<OutputResource> OutputResourcePtr;
typedef std::vector<OutputResourcePtr> OutputResourceVector;

// Server-specific context and platform adaption: threads, file system, locking,
// and so on.
// TODO(piatek): This file was renamed from resource_manager.h -- there are
//               some associated fixes outstanding --
// 1. abc of includes and class declarations.
// 2. Rename variables, data members, parameters, etc.
// 3. Rename methods.
class ServerContext {
 public:
  typedef std::pair<RewriteOptions*, bool> OptionsBoolPair;

  // The lifetime for cache-extended generated resources, in milliseconds.
  static const int64 kGeneratedMaxAgeMs;

  // This value is a shared constant so that it can also be used in
  // the Apache-specific code that repairs our caching headers downstream
  // of mod_headers.
  static const char kResourceEtagValue[];
  static const char kCacheKeyResourceNamePrefix[];

  // Default statistics group name.
  static const char kStatisticsGroup[];

  explicit ServerContext(RewriteDriverFactory* factory);
  virtual ~ServerContext();

  // Set time and cache headers with long TTL (including Date, Last-Modified,
  // Cache-Control, Etags, Expires).
  //
  // Also sets Content-Type headers if content_type is provided.
  // If content_type is null, the Content-Type header is omitted.
  void SetDefaultLongCacheHeaders(const ContentType* content_type,
                                  ResponseHeaders* header) const {
    SetDefaultLongCacheHeadersWithCharset(content_type, StringPiece(), header);
  }

  // As above, but also sets charset if it's non-empty and content_type
  // is non-NULL.
  void SetDefaultLongCacheHeadersWithCharset(
      const ContentType* content_type, StringPiece charset,
      ResponseHeaders* header) const;

  void set_filename_prefix(const StringPiece& file_prefix);
  void set_statistics(Statistics* x) { statistics_ = x; }
  void set_rewrite_stats(RewriteStats* x) { rewrite_stats_ = x; }
  void set_lock_manager(NamedLockManager* x) { lock_manager_ = x; }
  void set_enable_property_cache(bool enabled);
  void set_message_handler(MessageHandler* x) { message_handler_ = x; }

  StringPiece filename_prefix() const { return file_prefix_; }
  Statistics* statistics() const { return statistics_; }
  NamedLockManager* lock_manager() const { return lock_manager_; }
  RewriteDriverFactory* factory() const { return factory_; }
  ThreadSynchronizer* thread_synchronizer() {
    return thread_synchronizer_.get();
  }
  ExperimentMatcher* experiment_matcher() { return experiment_matcher_.get(); }

  // Computes the most restrictive Cache-Control intersection of the input
  // resources, and the provided headers, and sets that cache-control on the
  // provided headers.  Does nothing if all of the resources are fully
  // cacheable, since in that case we will want to cache-extend.
  //
  // Disregards Cache-Control directives other than max-age, no-cache, no-store,
  // and private, and strips them if any resource is no-cache or private.  By
  // assumption, a resource can only be no-store if it is also no-cache.
  void ApplyInputCacheControl(const ResourceVector& inputs,
                              ResponseHeaders* headers);

  // Is this URL a ref to a Pagespeed resource?
  bool IsPagespeedResource(const GoogleUrl& url);

  // Returns a filter to be used for decoding URLs & options for given
  // filter id. This should not be used for actual fetches.
  const RewriteFilter* FindFilterForDecoding(const StringPiece& id) const;

  // See RewriteDriver::DecodeUrl.
  bool DecodeUrlGivenOptions(const GoogleUrl& url,
                             const RewriteOptions* options,
                             const UrlNamer* url_namer,
                             StringVector* decoded_urls) const;

  void ComputeSignature(RewriteOptions* rewrite_options) const;

  // TODO(jmarantz): check thread safety in Apache.
  Hasher* hasher() const { return hasher_; }
  const Hasher* lock_hasher() const { return &lock_hasher_; }
  const Hasher* contents_hasher() const { return &contents_hasher_; }
  FileSystem* file_system() { return file_system_; }
  void set_file_system(FileSystem* fs ) { file_system_ = fs; }
  UrlNamer* url_namer() const { return url_namer_; }
  void set_url_namer(UrlNamer* n) { url_namer_ = n; }
  RewriteOptionsManager* rewrite_options_manager() const {
    return rewrite_options_manager_.get();
  }
  // Takes ownership of RewriteOptionsManager.
  void SetRewriteOptionsManager(RewriteOptionsManager* rom);
  StaticAssetManager* static_asset_manager() const {
    return static_asset_manager_;
  }
  void set_static_asset_manager(StaticAssetManager* manager) {
    static_asset_manager_ = manager;
  }
  Scheduler* scheduler() const { return scheduler_; }
  void set_scheduler(Scheduler* s) { scheduler_ = s; }
  bool has_default_system_fetcher() const {
    return default_system_fetcher_ != NULL;
  }
  bool has_default_distributed_fetcher() {
    return default_distributed_fetcher_ != NULL;
  }
  // Note: for rewriting user content, you want to use RewriteDriver's
  // async_fetcher() instead, as it may apply session-specific optimizations.
  UrlAsyncFetcher* DefaultSystemFetcher() { return default_system_fetcher_; }

  UrlAsyncFetcher* DefaultDistributedFetcher() {
    return default_distributed_fetcher_;
  }

  Timer* timer() const { return timer_; }

  // Note: doesn't take ownership.
  void set_timer(Timer* timer) { timer_ = timer; }

  HTTPCache* http_cache() const { return http_cache_.get(); }
  void set_http_cache(HTTPCache* x) { http_cache_.reset(x); }

  // Creates PagePropertyCache object with the provided PropertyStore object.
  void MakePagePropertyCache(PropertyStore* property_store);

  PropertyCache* page_property_cache() const {
    return page_property_cache_.get();
  }

  const PropertyCache::Cohort* dom_cohort() const { return dom_cohort_; }
  void set_dom_cohort(const PropertyCache::Cohort* c) { dom_cohort_ = c; }

  const PropertyCache::Cohort* blink_cohort() const { return blink_cohort_; }
  void set_blink_cohort(const PropertyCache::Cohort* c) { blink_cohort_ = c; }

  const PropertyCache::Cohort* beacon_cohort() const { return beacon_cohort_; }
  void set_beacon_cohort(const PropertyCache::Cohort* c) { beacon_cohort_ = c; }

  const PropertyCache::Cohort* fix_reflow_cohort() const {
    return fix_reflow_cohort_;
  }
  void set_fix_reflow_cohort(const PropertyCache::Cohort* c) {
    fix_reflow_cohort_ = c;
  }

  // Cache for storing file system metadata. It must be private to a server,
  // preferably but not necessarily shared between its processes, and is
  // required if using load-from-file and memcached (or any cache shared
  // between servers). This class does not take ownership.
  CacheInterface* filesystem_metadata_cache() const {
    return filesystem_metadata_cache_;
  }
  void set_filesystem_metadata_cache(CacheInterface* x) {
    filesystem_metadata_cache_ = x;
  }

  // Cache for small non-HTTP objects. This class does not take ownership.
  //
  // Note that this might share namespace with the HTTP cache, so make sure
  // your key names do not start with http://.
  CacheInterface* metadata_cache() const { return metadata_cache_; }
  void set_metadata_cache(CacheInterface* x) { metadata_cache_ = x; }

  CriticalCssFinder* critical_css_finder() const {
    return critical_css_finder_.get();
  }
  void set_critical_css_finder(CriticalCssFinder* finder);

  CriticalImagesFinder* critical_images_finder() const {
    return critical_images_finder_.get();
  }
  void set_critical_images_finder(CriticalImagesFinder* finder);

  CriticalSelectorFinder* critical_selector_finder() const {
    return critical_selector_finder_.get();
  }
  void set_critical_selector_finder(CriticalSelectorFinder* finder);

  FlushEarlyInfoFinder* flush_early_info_finder() const {
    return flush_early_info_finder_.get();
  }
  void set_flush_early_info_finder(FlushEarlyInfoFinder* finder);

  UserAgentMatcher* user_agent_matcher() const {
    return user_agent_matcher_;
  }
  void set_user_agent_matcher(UserAgentMatcher* n) { user_agent_matcher_ = n; }

  CacheHtmlInfoFinder* cache_html_info_finder() const {
    return cache_html_info_finder_.get();
  }

  SimpleRandom* simple_random() {
    return &simple_random_;
  }

  void set_cache_html_info_finder(CacheHtmlInfoFinder* finder);

  CriticalLineInfoFinder* critical_line_info_finder() const {
    return critical_line_info_finder_.get();
  }

  // Takes ownership of the passed in finder.
  void set_critical_line_info_finder(CriticalLineInfoFinder* finder);

  // Whether or not dumps of rewritten resources should be stored to
  // the filesystem. This is meant for testing purposes only.
  bool store_outputs_in_file_system() { return store_outputs_in_file_system_; }
  void set_store_outputs_in_file_system(bool store) {
    store_outputs_in_file_system_ = store;
  }

  RewriteStats* rewrite_stats() const { return rewrite_stats_; }
  MessageHandler* message_handler() const { return message_handler_; }

  // Allocate an NamedLock to guard the creation of the given resource.  If the
  // object is expensive to create, this lock should be held during its creation
  // to avoid multiple rewrites happening at once.  The lock will be unlocked
  // when creation_lock is reset or destructed.
  NamedLock* MakeCreationLock(const GoogleString& name);

  // Makes a lock used for fetching and optimizing an input resource.
  NamedLock* MakeInputLock(const GoogleString& name);

  // Attempt to obtain a named lock without blocking.  Return true if we do so.
  bool TryLockForCreation(NamedLock* creation_lock);

  // Attempt to obtain a named lock. When the lock has been obtained, queue the
  // callback on the  given worker Sequence.  If the lock times out, cancel the
  // callback, running the cancel on the worker.
  void LockForCreation(NamedLock* creation_lock,
                       QueuedWorkerPool::Sequence* worker, Function* callback);

  // Setters should probably only be used in testing.
  void set_hasher(Hasher* hasher) { hasher_ = hasher; }
  void set_default_system_fetcher(UrlAsyncFetcher* fetcher) {
    default_system_fetcher_ = fetcher;
  }
  void set_default_distributed_fetcher(UrlAsyncFetcher* fetcher) {
    default_distributed_fetcher_ = fetcher;
  }

  // Handles an incoming beacon request by incrementing the appropriate
  // variables.  Returns true if the url was parsed and handled correctly; in
  // this case a 204 No Content response should be sent.  Returns false if the
  // url could not be parsed; in this case the request should be declined. body
  // should be either the query params or the POST body, depending on how the
  // beacon was sent, from the beacon request.
  bool HandleBeacon(StringPiece body,
                    StringPiece user_agent,
                    const RequestContextPtr& request_context);

  // Returns a pointer to the master global_options.  These are not used
  // directly in RewriteDrivers, but are Cloned into the drivers as they
  // are created.  We generally do not expect global_options() to change once
  // the system is processing requests, except in Apache when someone does
  // a cache-flush by touching a file "cache.flush" in the file-cache directory.
  RewriteOptions* global_options();

  // Returns a pointer to the master global_options without modifying the
  // ServerContext.
  const RewriteOptions* global_options() const;

  // Note that you have to ensure the argument has the right type in case
  // a subclass of RewriteOptions is in use. This should also not be called
  // once request processing has commenced.
  void reset_global_options(RewriteOptions* options);

  // Makes a new, empty set of RewriteOptions.
  RewriteOptions* NewOptions();

  // Runs the rewrite_query parser for any options set in query-params
  // or in the headers. If all the pagespeed options that were parsed
  // were valid, they are available in rewrite_query->options().
  //
  // True is returned in two cases:
  //    - Valid PageSpeed query params or headers were parsed
  //    - No PageSpeed query-parameters or headers were found.
  // False is returned if there were PageSpeed-related options but they were
  // not valid.
  //
  // It also strips off the PageSpeed query parameters and headers from the
  // request_url, request headers, and response headers respectively. Stripped
  // query params are copied into rewrite_query->pagespeed_query_params().
  bool GetQueryOptions(GoogleUrl* request_url,
                       RequestHeaders* request_headers,
                       ResponseHeaders* response_headers,
                       RewriteQuery* rewrite_query);

  // Checks the url for the split html ATF/BTF query param. If present, it
  // strips the param from the url, and sets a bit in the request context
  // indicating which chunk of the split response was requested.
  // Returns true if it found a query param.
  static bool ScanSplitHtmlRequest(const RequestContextPtr& ctx,
                                   const RewriteOptions* options,
                                   GoogleString* url);

  // Returns any custom options required for this request, incorporating
  // any domain-specific options from the UrlNamer, options set in query-params,
  // and options set in request headers.
  // Takes ownership of domain_options and query_options.
  RewriteOptions* GetCustomOptions(RequestHeaders* request_headers,
                                   RewriteOptions* domain_options,
                                   RewriteOptions* query_options);

  // Returns the RewriteOptions signature hash.
  // Returns empty string if RewriteOptions is NULL.
  GoogleString GetRewriteOptionsSignatureHash(const RewriteOptions* options);

  // Generates a new managed RewriteDriver using the RewriteOptions
  // managed by this class.  Each RewriteDriver is not thread-safe,
  // but you can generate a RewriteDriver* for each thread.  The
  // returned drivers manage themselves: when the HTML parsing and
  // rewriting is done they will be returned to the pool.
  //
  // Filters allocated using this mechanism have their filter-chain
  // already frozen (see AddFilters()).
  RewriteDriver* NewRewriteDriver(const RequestContextPtr& request_ctx);

  // As above, but uses a specific RewriteDriverPool to determine the options
  // and manage the lifetime of the result. 'pool' must not be NULL.
  RewriteDriver* NewRewriteDriverFromPool(
      RewriteDriverPool* pool, const RequestContextPtr& request_ctx);

  // Generates a new unmanaged RewriteDriver with given RewriteOptions,
  // which are assumed to correspond to drivers managed by 'pool'
  // (which may be NULL if the options are custom).  Each RewriteDriver is
  // not thread-safe, but you can generate a RewriteDriver* for each thread.
  // The returned drivers must be explicitly deleted by the caller.
  //
  // RewriteDrivers allocated using this mechanism have not yet frozen
  // their filters, and so callers may explicitly enable individual
  // filters on the driver -- beyond those indicated in the options.
  // After all extra filters are added, AddFilters must be called to
  // freeze them and instantiate the filter-chain.
  //
  // Takes ownership of 'options'.
  RewriteDriver* NewUnmanagedRewriteDriver(
      RewriteDriverPool* pool, RewriteOptions* options,
      const RequestContextPtr& request_ctx);

  // Like NewUnmanagedRewriteDriver, but uses standard semi-automatic
  // memory management for RewriteDrivers.
  //
  // NOTE: This does not merge custom_options with global_options(), the
  // caller must do that if they want them merged.
  //
  // Filters allocated using this mechanism have their filter-chain
  // already frozen (see AddFilters()).
  //
  // Takes ownership of 'custom_options'.
  RewriteDriver* NewCustomRewriteDriver(
      RewriteOptions* custom_options, const RequestContextPtr& request_ctx);

  // Puts a RewriteDriver back on the free pool.  This is intended to
  // be called by a RewriteDriver on itself, once all pending
  // activites on it have completed, including HTML Parsing
  // (FinishParse) and all pending Rewrites.
  //
  // TODO(jmarantz): this cannot recycle RewriteDrivers with custom
  // rewrite options, which is a potential performance issue for Apache
  // installations that set custom options in .htaccess files, where
  // essentially every RewriteDriver will be a custom driver.  To
  // resolve this we need to make a comparator for RewriteOptions
  // so that we can determine option-equivalence and, potentially,
  // keep free-lists for each unique option-set.
  void ReleaseRewriteDriver(RewriteDriver* rewrite_driver);

  ThreadSystem* thread_system() { return thread_system_; }
  UsageDataReporter* usage_data_reporter() { return usage_data_reporter_; }

  // Calling this method will stop results of rewrites being cached in the
  // metadata cache. This is meant for the shutdown sequence.
  void set_shutting_down() {
    shutting_down_.set_value(true);
  }

  bool shutting_down() const {
    return shutting_down_.value();
  }

  // Waits a bounded amount of time for all currently running jobs to
  // complete.  This is meant for use when shutting down processing,
  // so that jobs running in background do not access objects that are
  // about to be deleted.  If there are long-running outstanding tasks,
  // the drivers may stay running past this call.
  //
  // TODO(jmarantz): Change New*RewriteDriver() calls to return NULL
  // when run after shutdown.  This requires changing call-sites to
  // null-check their drivers and gracefully fail.
  void ShutDownDrivers();

  // Take any headers that are not caching-related, and not otherwise
  // filled in by SetDefaultLongCacheHeaders or SetContentType, but
  // *were* set on the input resource, and copy them to the output
  // resource.  This allows user headers to be preserved.  This must
  // be called as needed by individual filters, prior to Write().
  //
  // Note that this API is only usable for single-input rewriters.
  // Combiners will need to execute some kind of merge, union, or
  // intersection policy, if we wish to preserve origin response
  // headers.
  //
  // Note: this does not call ComputeCaching() on the output headers,
  // so that method must be called prior to invoking any caching predicates
  // on the output's ResponseHeader.  In theory we shouldn't mark the
  // caching bits dirty because we are only adding headers that will
  // not affect caching, but at the moment the dirty-bit is set independent
  // of that.
  //
  // TODO(jmarantz): avoid setting caching_dirty bit in ResponseHeaders when
  // the header is not caching-related.
  void MergeNonCachingResponseHeaders(const ResourcePtr& input,
                                      const OutputResourcePtr& output) {
    MergeNonCachingResponseHeaders(*input->response_headers(),
                                   output->response_headers());
  }

  // Entry-point with the same functionality, exposed for easier testing.
  void MergeNonCachingResponseHeaders(const ResponseHeaders& input_headers,
                                      ResponseHeaders* output_headers);

  // Pool of worker-threads that can be used to handle html-parsing.
  QueuedWorkerPool* html_workers() { return html_workers_; }

  // Pool of worker-threads that can be used to handle resource rewriting.
  QueuedWorkerPool* rewrite_workers() { return rewrite_workers_; }

  // Pool of worker-threads that can be used to handle low-priority/high CPU
  // portions of resource rewriting.
  QueuedWorkerPool* low_priority_rewrite_workers() {
    return low_priority_rewrite_workers_;
  }

  // Returns the number of rewrite drivers that we were aware of at the
  // time of the call. This includes those created via NewCustomRewriteDriver
  // and NewRewriteDriver, but not via NewUnmanagedRewriteDriver.
  size_t num_active_rewrite_drivers();

  // A ServerContext may be created in one phase, and later populated
  // with all its dependencies.  This populates the worker threads.
  void InitWorkers();

  // Returns whether or not this attribute can be merged into headers
  // without additional considerations.
  static bool IsExcludedAttribute(const char* attribute);

  // Determines whether we can assume that the response headers we see
  // in rewrite_drivers when filters are applied reflect the final
  // form from the origin.  In proxy applications, this is generally
  // true.  But in Apache, it depends when the output_filter is
  // applied relative to mod_headers and mod_expires.
  //
  // The default-value is 'true'.
  bool response_headers_finalized() const {
    return response_headers_finalized_;
  }
  void set_response_headers_finalized(bool x) {
    response_headers_finalized_ = x;
  }

  // Returns the RewriteDriverPool that's used by NewRewriteDriver (so calling
  // NewRewriteDriverFromPool(standard_rewrite_driver_pool()) is equivalent to
  // calling NewRewriteDriver.
  RewriteDriverPool* standard_rewrite_driver_pool() {
    return available_rewrite_drivers_.get();
  }

  // Returns the current server hostname.
  const GoogleString& hostname() const {
    return hostname_;
  }
  void set_hostname(const GoogleString& x) {
    hostname_ = x;
  }

  // Adds an X-Original-Content-Length header to the response headers
  // based on the size of the input resources.
  void AddOriginalContentLengthHeader(const ResourceVector& inputs,
                                      ResponseHeaders* headers);

  // Chooses a driver pool based on the request protocol.
  virtual RewriteDriverPool* SelectDriverPool(bool using_spdy);

  // Provides a hook for ServerContext implementations to determine
  // the fetcher implementation based on the request.
  virtual void ApplySessionFetchers(const RequestContextPtr& req,
                                    RewriteDriver* driver);

  // Determines whether in this server, it makes sense to proxy HTML
  // from external sources.  If we're acting as a reverse proxy that
  // talks to the backend over HTTP, it makes sense to set this to
  // 'true'.  The JavaScript loaded from the HTML on the origin
  // domain will be given full access to cookies on the proxied
  // domain.
  //
  // For resource-proxying (e.g. ModPagespeedMapProxyDomain) this should
  // be set to 'false' as that command is intended only for reosurces, not
  // for HTML.
  virtual bool ProxiesHtml() const = 0;

  // Makes a new RequestProperties.
  RequestProperties* NewRequestProperties();

  // Puts the cache on a list to be destroyed at the last phase of system
  // shutdown.
  void DeleteCacheOnDestruction(CacheInterface* cache);

  void set_cache_property_store(CachePropertyStore* p);

  // Set the RewriteDriver that will be used to decode .pagespeed. URLs.
  // Does not take ownership.
  void set_decoding_driver(RewriteDriver* rd) { decoding_driver_ = rd; }

  // Creates CachePropertyStore object which will be used by PagePropertyCache.
  virtual PropertyStore* CreatePropertyStore(CacheInterface* cache_backend);

  // Establishes a new Cohort for this property.
  // This will also call CachePropertyStore::AddCohort() if CachePropertyStore
  // is used.
  const PropertyCache::Cohort* AddCohort(
      const GoogleString& cohort_name,
      PropertyCache* pcache);

  // Establishes a new Cohort to be backed by the specified CacheInterface.
  // NOTE: Does not take ownership of the CacheInterface object.
  // This also calls CachePropertyStore::AddCohort() to set the cache backend
  // for the given cohort.
  const PropertyCache::Cohort* AddCohortWithCache(
      const GoogleString& cohort_name,
      CacheInterface* cache,
      PropertyCache* pcache);

  // Returns the cache backend associated with CachePropertyStore.
  // Returns NULL if non-CachePropertyStore is used.
  const CacheInterface* pcache_cache_backend();

  const pagespeed::js::JsTokenizerPatterns* js_tokenizer_patterns() const {
    return js_tokenizer_patterns_;
  }

  // Shows cached data related to a URL.  Ownership of options is transferred
  // to this function.
  void ShowCacheHandler(StringPiece url, AsyncFetch* fetch,
                        RewriteOptions* options);

  // Returns an HTML form for entering a URL for ShowCacheHandler.  If
  // the user_agent is non-null, then it's used to prepopulate the
  // "User Agent" field in the form.
  GoogleString ShowCacheForm(const char* user_agent) const;

 protected:
  // Takes ownership of the given pool, making sure to clean it up at the
  // appropriate spot during shutdown.
  void ManageRewriteDriverPool(RewriteDriverPool* pool) {
    additional_driver_pools_.push_back(pool);
  }

 private:
  friend class ServerContextTest;
  typedef std::set<RewriteDriver*> RewriteDriverSet;

  // Must be called with rewrite_drivers_mutex_ held.
  void ReleaseRewriteDriverImpl(RewriteDriver* rewrite_driver);

  // These are normally owned by the RewriteDriverFactory that made 'this'.
  ThreadSystem* thread_system_;
  RewriteStats* rewrite_stats_;
  GoogleString file_prefix_;
  FileSystem* file_system_;
  UrlNamer* url_namer_;
  scoped_ptr<RewriteOptionsManager> rewrite_options_manager_;
  UserAgentMatcher* user_agent_matcher_;
  Scheduler* scheduler_;
  UrlAsyncFetcher* default_system_fetcher_;
  UrlAsyncFetcher* default_distributed_fetcher_;
  Hasher* hasher_;
  scoped_ptr<CriticalImagesFinder> critical_images_finder_;
  scoped_ptr<CriticalCssFinder> critical_css_finder_;
  scoped_ptr<CriticalSelectorFinder> critical_selector_finder_;
  scoped_ptr<CacheHtmlInfoFinder> cache_html_info_finder_;
  scoped_ptr<FlushEarlyInfoFinder> flush_early_info_finder_;
  scoped_ptr<CriticalLineInfoFinder> critical_line_info_finder_;

  // hasher_ is often set to a mock within unit tests, but some parts of the
  // system will not work sensibly if the "hash algorithm" used always returns
  // constants. For those, we have two separate hashers.
  MD5Hasher lock_hasher_;  // Used to compute named lock names.

  // Used to hash file contents to see if inputs to a rewrites have actually
  // changed (and didn't just expire).
  MD5Hasher contents_hasher_;

  Statistics* statistics_;

  Timer* timer_;
  scoped_ptr<HTTPCache> http_cache_;
  scoped_ptr<PropertyCache> page_property_cache_;
  CacheInterface* filesystem_metadata_cache_;
  CacheInterface* metadata_cache_;

  bool store_outputs_in_file_system_;
  bool response_headers_finalized_;
  bool enable_property_cache_;

  NamedLockManager* lock_manager_;
  MessageHandler* message_handler_;

  const PropertyCache::Cohort* dom_cohort_;
  const PropertyCache::Cohort* blink_cohort_;
  const PropertyCache::Cohort* beacon_cohort_;
  const PropertyCache::Cohort* fix_reflow_cohort_;

  // RewriteDrivers that were previously allocated, but have
  // been released with ReleaseRewriteDriver, and are ready
  // for re-use with NewRewriteDriver.
  // Protected by rewrite_drivers_mutex_.
  // TODO(morlovich): Give this a better name in an immediate follow up.
  scoped_ptr<RewriteDriverPool> available_rewrite_drivers_;

  // Other RewriteDriverPool's whose lifetime we help manage for our subclasses.
  std::vector<RewriteDriverPool*> additional_driver_pools_;

  // RewriteDrivers that are currently in use.  This is retained
  // as a sanity check to make sure our system is coherent,
  // and to facilitate complete cleanup if a Shutdown occurs
  // while a request is in flight.
  // Protected by rewrite_drivers_mutex_.
  RewriteDriverSet active_rewrite_drivers_;

  // If this value is true ReleaseRewriteDriver will just insert its
  // argument into deferred_release_rewrite_drivers_ rather
  // than try to delete or recycle it. This is used for shutdown
  // so that the main thread does not have to worry about rewrite threads
  // deleting RewriteDrivers or altering active_rewrite_drivers_.
  //
  // Protected by rewrite_drivers_mutex_.
  bool trying_to_cleanup_rewrite_drivers_;
  RewriteDriverSet deferred_release_rewrite_drivers_;
  bool shutdown_drivers_called_;

  // If set, a RewriteDriverFactory provides a mechanism to add
  // platform-specific filters to a RewriteDriver.
  RewriteDriverFactory* factory_;

  scoped_ptr<AbstractMutex> rewrite_drivers_mutex_;

  // All access, even internal to the class, should be via options() so
  // subclasses can override.
  scoped_ptr<RewriteOptions> base_class_options_;

  // This is owned by the RewriteDriverFactory. We use it for just for decoding
  // resource URLs, using the default options.  This is possible because the
  // id->RewriteFilter table is fully constructed independent of the options.
  RewriteDriver* decoding_driver_;

  QueuedWorkerPool* html_workers_;  // Owned by the factory
  QueuedWorkerPool* rewrite_workers_;  // Owned by the factory
  QueuedWorkerPool* low_priority_rewrite_workers_;  // Owned by the factory

  AtomicBool shutting_down_;

  // Used to create URLs for various filter static js and image files.
  StaticAssetManager* static_asset_manager_;

  // Used to help inject sync-points into thread-intensive code for the purposes
  // of controlling thread interleaving to test code for possible races.
  scoped_ptr<ThreadSynchronizer> thread_synchronizer_;

  // Used to match clients or sessions to a specific experiment.
  scoped_ptr<ExperimentMatcher> experiment_matcher_;

  UsageDataReporter* usage_data_reporter_;

  // A convenient central place to store the hostname we're running on.
  GoogleString hostname_;

  // A simple (and always seeded with the same default!) random number
  // generator.  Do not use for security purposes.
  SimpleRandom simple_random_;
  // Owned by RewriteDriverFactory.
  const pagespeed::js::JsTokenizerPatterns* js_tokenizer_patterns_;

  scoped_ptr<CachePropertyStore> cache_property_store_;

  DISALLOW_COPY_AND_ASSIGN(ServerContext);
};

}  // namespace net_instaweb

#endif  // NET_INSTAWEB_REWRITER_PUBLIC_SERVER_CONTEXT_H_
