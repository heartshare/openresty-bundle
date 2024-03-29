// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: net/instaweb/rewriter/critical_keys.proto

#ifndef PROTOBUF_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto__INCLUDED
#define PROTOBUF_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
// @@protoc_insertion_point(includes)

namespace net_instaweb {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
void protobuf_AssignDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();

class CriticalKeys;
class CriticalKeys_KeyEvidence;
class CriticalKeys_PendingNonce;

// ===================================================================

class CriticalKeys_KeyEvidence : public ::google::protobuf::MessageLite {
 public:
  CriticalKeys_KeyEvidence();
  virtual ~CriticalKeys_KeyEvidence();

  CriticalKeys_KeyEvidence(const CriticalKeys_KeyEvidence& from);

  inline CriticalKeys_KeyEvidence& operator=(const CriticalKeys_KeyEvidence& from) {
    CopyFrom(from);
    return *this;
  }

  static const CriticalKeys_KeyEvidence& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const CriticalKeys_KeyEvidence* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(CriticalKeys_KeyEvidence* other);

  // implements Message ----------------------------------------------

  CriticalKeys_KeyEvidence* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const CriticalKeys_KeyEvidence& from);
  void MergeFrom(const CriticalKeys_KeyEvidence& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string key = 1;
  inline bool has_key() const;
  inline void clear_key();
  static const int kKeyFieldNumber = 1;
  inline const ::std::string& key() const;
  inline void set_key(const ::std::string& value);
  inline void set_key(const char* value);
  inline void set_key(const char* value, size_t size);
  inline ::std::string* mutable_key();
  inline ::std::string* release_key();
  inline void set_allocated_key(::std::string* key);

  // optional int32 support = 2;
  inline bool has_support() const;
  inline void clear_support();
  static const int kSupportFieldNumber = 2;
  inline ::google::protobuf::int32 support() const;
  inline void set_support(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:net_instaweb.CriticalKeys.KeyEvidence)
 private:
  inline void set_has_key();
  inline void clear_has_key();
  inline void set_has_support();
  inline void clear_has_support();

  ::std::string* key_;
  ::google::protobuf::int32 support_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
  #endif
  friend void protobuf_AssignDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
  friend void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();

  void InitAsDefaultInstance();
  static CriticalKeys_KeyEvidence* default_instance_;
};
// -------------------------------------------------------------------

class CriticalKeys_PendingNonce : public ::google::protobuf::MessageLite {
 public:
  CriticalKeys_PendingNonce();
  virtual ~CriticalKeys_PendingNonce();

  CriticalKeys_PendingNonce(const CriticalKeys_PendingNonce& from);

  inline CriticalKeys_PendingNonce& operator=(const CriticalKeys_PendingNonce& from) {
    CopyFrom(from);
    return *this;
  }

  static const CriticalKeys_PendingNonce& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const CriticalKeys_PendingNonce* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(CriticalKeys_PendingNonce* other);

  // implements Message ----------------------------------------------

  CriticalKeys_PendingNonce* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const CriticalKeys_PendingNonce& from);
  void MergeFrom(const CriticalKeys_PendingNonce& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int64 timestamp_ms = 1;
  inline bool has_timestamp_ms() const;
  inline void clear_timestamp_ms();
  static const int kTimestampMsFieldNumber = 1;
  inline ::google::protobuf::int64 timestamp_ms() const;
  inline void set_timestamp_ms(::google::protobuf::int64 value);

  // optional string nonce = 2;
  inline bool has_nonce() const;
  inline void clear_nonce();
  static const int kNonceFieldNumber = 2;
  inline const ::std::string& nonce() const;
  inline void set_nonce(const ::std::string& value);
  inline void set_nonce(const char* value);
  inline void set_nonce(const char* value, size_t size);
  inline ::std::string* mutable_nonce();
  inline ::std::string* release_nonce();
  inline void set_allocated_nonce(::std::string* nonce);

  // @@protoc_insertion_point(class_scope:net_instaweb.CriticalKeys.PendingNonce)
 private:
  inline void set_has_timestamp_ms();
  inline void clear_has_timestamp_ms();
  inline void set_has_nonce();
  inline void clear_has_nonce();

  ::google::protobuf::int64 timestamp_ms_;
  ::std::string* nonce_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
  #endif
  friend void protobuf_AssignDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
  friend void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();

  void InitAsDefaultInstance();
  static CriticalKeys_PendingNonce* default_instance_;
};
// -------------------------------------------------------------------

class CriticalKeys : public ::google::protobuf::MessageLite {
 public:
  CriticalKeys();
  virtual ~CriticalKeys();

  CriticalKeys(const CriticalKeys& from);

  inline CriticalKeys& operator=(const CriticalKeys& from) {
    CopyFrom(from);
    return *this;
  }

  static const CriticalKeys& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const CriticalKeys* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(CriticalKeys* other);

  // implements Message ----------------------------------------------

  CriticalKeys* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const CriticalKeys& from);
  void MergeFrom(const CriticalKeys& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::std::string GetTypeName() const;

  // nested types ----------------------------------------------------

  typedef CriticalKeys_KeyEvidence KeyEvidence;
  typedef CriticalKeys_PendingNonce PendingNonce;

  // accessors -------------------------------------------------------

  // optional int64 next_beacon_timestamp_ms = 4;
  inline bool has_next_beacon_timestamp_ms() const;
  inline void clear_next_beacon_timestamp_ms();
  static const int kNextBeaconTimestampMsFieldNumber = 4;
  inline ::google::protobuf::int64 next_beacon_timestamp_ms() const;
  inline void set_next_beacon_timestamp_ms(::google::protobuf::int64 value);

  // repeated .net_instaweb.CriticalKeys.KeyEvidence key_evidence = 5;
  inline int key_evidence_size() const;
  inline void clear_key_evidence();
  static const int kKeyEvidenceFieldNumber = 5;
  inline const ::net_instaweb::CriticalKeys_KeyEvidence& key_evidence(int index) const;
  inline ::net_instaweb::CriticalKeys_KeyEvidence* mutable_key_evidence(int index);
  inline ::net_instaweb::CriticalKeys_KeyEvidence* add_key_evidence();
  inline const ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_KeyEvidence >&
      key_evidence() const;
  inline ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_KeyEvidence >*
      mutable_key_evidence();

  // repeated .net_instaweb.CriticalKeys.PendingNonce pending_nonce = 6;
  inline int pending_nonce_size() const;
  inline void clear_pending_nonce();
  static const int kPendingNonceFieldNumber = 6;
  inline const ::net_instaweb::CriticalKeys_PendingNonce& pending_nonce(int index) const;
  inline ::net_instaweb::CriticalKeys_PendingNonce* mutable_pending_nonce(int index);
  inline ::net_instaweb::CriticalKeys_PendingNonce* add_pending_nonce();
  inline const ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_PendingNonce >&
      pending_nonce() const;
  inline ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_PendingNonce >*
      mutable_pending_nonce();

  // optional int32 maximum_possible_support = 7 [default = 1];
  inline bool has_maximum_possible_support() const;
  inline void clear_maximum_possible_support();
  static const int kMaximumPossibleSupportFieldNumber = 7;
  inline ::google::protobuf::int32 maximum_possible_support() const;
  inline void set_maximum_possible_support(::google::protobuf::int32 value);

  // optional int64 valid_beacons_received = 8;
  inline bool has_valid_beacons_received() const;
  inline void clear_valid_beacons_received();
  static const int kValidBeaconsReceivedFieldNumber = 8;
  inline ::google::protobuf::int64 valid_beacons_received() const;
  inline void set_valid_beacons_received(::google::protobuf::int64 value);

  // optional int64 nonces_recently_expired = 9;
  inline bool has_nonces_recently_expired() const;
  inline void clear_nonces_recently_expired();
  static const int kNoncesRecentlyExpiredFieldNumber = 9;
  inline ::google::protobuf::int64 nonces_recently_expired() const;
  inline void set_nonces_recently_expired(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:net_instaweb.CriticalKeys)
 private:
  inline void set_has_next_beacon_timestamp_ms();
  inline void clear_has_next_beacon_timestamp_ms();
  inline void set_has_maximum_possible_support();
  inline void clear_has_maximum_possible_support();
  inline void set_has_valid_beacons_received();
  inline void clear_has_valid_beacons_received();
  inline void set_has_nonces_recently_expired();
  inline void clear_has_nonces_recently_expired();

  ::google::protobuf::int64 next_beacon_timestamp_ms_;
  ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_KeyEvidence > key_evidence_;
  ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_PendingNonce > pending_nonce_;
  ::google::protobuf::int64 valid_beacons_received_;
  ::google::protobuf::int64 nonces_recently_expired_;
  ::google::protobuf::int32 maximum_possible_support_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
  #endif
  friend void protobuf_AssignDesc_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();
  friend void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto();

  void InitAsDefaultInstance();
  static CriticalKeys* default_instance_;
};
// ===================================================================


// ===================================================================

// CriticalKeys_KeyEvidence

// optional string key = 1;
inline bool CriticalKeys_KeyEvidence::has_key() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CriticalKeys_KeyEvidence::set_has_key() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CriticalKeys_KeyEvidence::clear_has_key() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CriticalKeys_KeyEvidence::clear_key() {
  if (key_ != &::google::protobuf::internal::GetEmptyString()) {
    key_->clear();
  }
  clear_has_key();
}
inline const ::std::string& CriticalKeys_KeyEvidence::key() const {
  return *key_;
}
inline void CriticalKeys_KeyEvidence::set_key(const ::std::string& value) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::GetEmptyString()) {
    key_ = new ::std::string;
  }
  key_->assign(value);
}
inline void CriticalKeys_KeyEvidence::set_key(const char* value) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::GetEmptyString()) {
    key_ = new ::std::string;
  }
  key_->assign(value);
}
inline void CriticalKeys_KeyEvidence::set_key(const char* value, size_t size) {
  set_has_key();
  if (key_ == &::google::protobuf::internal::GetEmptyString()) {
    key_ = new ::std::string;
  }
  key_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CriticalKeys_KeyEvidence::mutable_key() {
  set_has_key();
  if (key_ == &::google::protobuf::internal::GetEmptyString()) {
    key_ = new ::std::string;
  }
  return key_;
}
inline ::std::string* CriticalKeys_KeyEvidence::release_key() {
  clear_has_key();
  if (key_ == &::google::protobuf::internal::GetEmptyString()) {
    return NULL;
  } else {
    ::std::string* temp = key_;
    key_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyString());
    return temp;
  }
}
inline void CriticalKeys_KeyEvidence::set_allocated_key(::std::string* key) {
  if (key_ != &::google::protobuf::internal::GetEmptyString()) {
    delete key_;
  }
  if (key) {
    set_has_key();
    key_ = key;
  } else {
    clear_has_key();
    key_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyString());
  }
}

// optional int32 support = 2;
inline bool CriticalKeys_KeyEvidence::has_support() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CriticalKeys_KeyEvidence::set_has_support() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CriticalKeys_KeyEvidence::clear_has_support() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CriticalKeys_KeyEvidence::clear_support() {
  support_ = 0;
  clear_has_support();
}
inline ::google::protobuf::int32 CriticalKeys_KeyEvidence::support() const {
  return support_;
}
inline void CriticalKeys_KeyEvidence::set_support(::google::protobuf::int32 value) {
  set_has_support();
  support_ = value;
}

// -------------------------------------------------------------------

// CriticalKeys_PendingNonce

// optional int64 timestamp_ms = 1;
inline bool CriticalKeys_PendingNonce::has_timestamp_ms() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CriticalKeys_PendingNonce::set_has_timestamp_ms() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CriticalKeys_PendingNonce::clear_has_timestamp_ms() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CriticalKeys_PendingNonce::clear_timestamp_ms() {
  timestamp_ms_ = GOOGLE_LONGLONG(0);
  clear_has_timestamp_ms();
}
inline ::google::protobuf::int64 CriticalKeys_PendingNonce::timestamp_ms() const {
  return timestamp_ms_;
}
inline void CriticalKeys_PendingNonce::set_timestamp_ms(::google::protobuf::int64 value) {
  set_has_timestamp_ms();
  timestamp_ms_ = value;
}

// optional string nonce = 2;
inline bool CriticalKeys_PendingNonce::has_nonce() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CriticalKeys_PendingNonce::set_has_nonce() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CriticalKeys_PendingNonce::clear_has_nonce() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CriticalKeys_PendingNonce::clear_nonce() {
  if (nonce_ != &::google::protobuf::internal::GetEmptyString()) {
    nonce_->clear();
  }
  clear_has_nonce();
}
inline const ::std::string& CriticalKeys_PendingNonce::nonce() const {
  return *nonce_;
}
inline void CriticalKeys_PendingNonce::set_nonce(const ::std::string& value) {
  set_has_nonce();
  if (nonce_ == &::google::protobuf::internal::GetEmptyString()) {
    nonce_ = new ::std::string;
  }
  nonce_->assign(value);
}
inline void CriticalKeys_PendingNonce::set_nonce(const char* value) {
  set_has_nonce();
  if (nonce_ == &::google::protobuf::internal::GetEmptyString()) {
    nonce_ = new ::std::string;
  }
  nonce_->assign(value);
}
inline void CriticalKeys_PendingNonce::set_nonce(const char* value, size_t size) {
  set_has_nonce();
  if (nonce_ == &::google::protobuf::internal::GetEmptyString()) {
    nonce_ = new ::std::string;
  }
  nonce_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* CriticalKeys_PendingNonce::mutable_nonce() {
  set_has_nonce();
  if (nonce_ == &::google::protobuf::internal::GetEmptyString()) {
    nonce_ = new ::std::string;
  }
  return nonce_;
}
inline ::std::string* CriticalKeys_PendingNonce::release_nonce() {
  clear_has_nonce();
  if (nonce_ == &::google::protobuf::internal::GetEmptyString()) {
    return NULL;
  } else {
    ::std::string* temp = nonce_;
    nonce_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyString());
    return temp;
  }
}
inline void CriticalKeys_PendingNonce::set_allocated_nonce(::std::string* nonce) {
  if (nonce_ != &::google::protobuf::internal::GetEmptyString()) {
    delete nonce_;
  }
  if (nonce) {
    set_has_nonce();
    nonce_ = nonce;
  } else {
    clear_has_nonce();
    nonce_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyString());
  }
}

// -------------------------------------------------------------------

// CriticalKeys

// optional int64 next_beacon_timestamp_ms = 4;
inline bool CriticalKeys::has_next_beacon_timestamp_ms() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CriticalKeys::set_has_next_beacon_timestamp_ms() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CriticalKeys::clear_has_next_beacon_timestamp_ms() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CriticalKeys::clear_next_beacon_timestamp_ms() {
  next_beacon_timestamp_ms_ = GOOGLE_LONGLONG(0);
  clear_has_next_beacon_timestamp_ms();
}
inline ::google::protobuf::int64 CriticalKeys::next_beacon_timestamp_ms() const {
  return next_beacon_timestamp_ms_;
}
inline void CriticalKeys::set_next_beacon_timestamp_ms(::google::protobuf::int64 value) {
  set_has_next_beacon_timestamp_ms();
  next_beacon_timestamp_ms_ = value;
}

// repeated .net_instaweb.CriticalKeys.KeyEvidence key_evidence = 5;
inline int CriticalKeys::key_evidence_size() const {
  return key_evidence_.size();
}
inline void CriticalKeys::clear_key_evidence() {
  key_evidence_.Clear();
}
inline const ::net_instaweb::CriticalKeys_KeyEvidence& CriticalKeys::key_evidence(int index) const {
  return key_evidence_.Get(index);
}
inline ::net_instaweb::CriticalKeys_KeyEvidence* CriticalKeys::mutable_key_evidence(int index) {
  return key_evidence_.Mutable(index);
}
inline ::net_instaweb::CriticalKeys_KeyEvidence* CriticalKeys::add_key_evidence() {
  return key_evidence_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_KeyEvidence >&
CriticalKeys::key_evidence() const {
  return key_evidence_;
}
inline ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_KeyEvidence >*
CriticalKeys::mutable_key_evidence() {
  return &key_evidence_;
}

// repeated .net_instaweb.CriticalKeys.PendingNonce pending_nonce = 6;
inline int CriticalKeys::pending_nonce_size() const {
  return pending_nonce_.size();
}
inline void CriticalKeys::clear_pending_nonce() {
  pending_nonce_.Clear();
}
inline const ::net_instaweb::CriticalKeys_PendingNonce& CriticalKeys::pending_nonce(int index) const {
  return pending_nonce_.Get(index);
}
inline ::net_instaweb::CriticalKeys_PendingNonce* CriticalKeys::mutable_pending_nonce(int index) {
  return pending_nonce_.Mutable(index);
}
inline ::net_instaweb::CriticalKeys_PendingNonce* CriticalKeys::add_pending_nonce() {
  return pending_nonce_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_PendingNonce >&
CriticalKeys::pending_nonce() const {
  return pending_nonce_;
}
inline ::google::protobuf::RepeatedPtrField< ::net_instaweb::CriticalKeys_PendingNonce >*
CriticalKeys::mutable_pending_nonce() {
  return &pending_nonce_;
}

// optional int32 maximum_possible_support = 7 [default = 1];
inline bool CriticalKeys::has_maximum_possible_support() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void CriticalKeys::set_has_maximum_possible_support() {
  _has_bits_[0] |= 0x00000008u;
}
inline void CriticalKeys::clear_has_maximum_possible_support() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void CriticalKeys::clear_maximum_possible_support() {
  maximum_possible_support_ = 1;
  clear_has_maximum_possible_support();
}
inline ::google::protobuf::int32 CriticalKeys::maximum_possible_support() const {
  return maximum_possible_support_;
}
inline void CriticalKeys::set_maximum_possible_support(::google::protobuf::int32 value) {
  set_has_maximum_possible_support();
  maximum_possible_support_ = value;
}

// optional int64 valid_beacons_received = 8;
inline bool CriticalKeys::has_valid_beacons_received() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void CriticalKeys::set_has_valid_beacons_received() {
  _has_bits_[0] |= 0x00000010u;
}
inline void CriticalKeys::clear_has_valid_beacons_received() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void CriticalKeys::clear_valid_beacons_received() {
  valid_beacons_received_ = GOOGLE_LONGLONG(0);
  clear_has_valid_beacons_received();
}
inline ::google::protobuf::int64 CriticalKeys::valid_beacons_received() const {
  return valid_beacons_received_;
}
inline void CriticalKeys::set_valid_beacons_received(::google::protobuf::int64 value) {
  set_has_valid_beacons_received();
  valid_beacons_received_ = value;
}

// optional int64 nonces_recently_expired = 9;
inline bool CriticalKeys::has_nonces_recently_expired() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void CriticalKeys::set_has_nonces_recently_expired() {
  _has_bits_[0] |= 0x00000020u;
}
inline void CriticalKeys::clear_has_nonces_recently_expired() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void CriticalKeys::clear_nonces_recently_expired() {
  nonces_recently_expired_ = GOOGLE_LONGLONG(0);
  clear_has_nonces_recently_expired();
}
inline ::google::protobuf::int64 CriticalKeys::nonces_recently_expired() const {
  return nonces_recently_expired_;
}
inline void CriticalKeys::set_nonces_recently_expired(::google::protobuf::int64 value) {
  set_has_nonces_recently_expired();
  nonces_recently_expired_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace net_instaweb

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_net_2finstaweb_2frewriter_2fcritical_5fkeys_2eproto__INCLUDED
