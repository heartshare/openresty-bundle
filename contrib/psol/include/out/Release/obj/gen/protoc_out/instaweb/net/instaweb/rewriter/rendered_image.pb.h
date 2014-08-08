// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: net/instaweb/rewriter/rendered_image.proto

#ifndef PROTOBUF_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto__INCLUDED
#define PROTOBUF_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto__INCLUDED

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
void  protobuf_AddDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();
void protobuf_AssignDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();
void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();

class RenderedImages;
class RenderedImages_Image;

// ===================================================================

class RenderedImages_Image : public ::google::protobuf::MessageLite {
 public:
  RenderedImages_Image();
  virtual ~RenderedImages_Image();

  RenderedImages_Image(const RenderedImages_Image& from);

  inline RenderedImages_Image& operator=(const RenderedImages_Image& from) {
    CopyFrom(from);
    return *this;
  }

  static const RenderedImages_Image& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const RenderedImages_Image* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(RenderedImages_Image* other);

  // implements Message ----------------------------------------------

  RenderedImages_Image* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const RenderedImages_Image& from);
  void MergeFrom(const RenderedImages_Image& from);
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

  // optional string src = 1;
  inline bool has_src() const;
  inline void clear_src();
  static const int kSrcFieldNumber = 1;
  inline const ::std::string& src() const;
  inline void set_src(const ::std::string& value);
  inline void set_src(const char* value);
  inline void set_src(const char* value, size_t size);
  inline ::std::string* mutable_src();
  inline ::std::string* release_src();
  inline void set_allocated_src(::std::string* src);

  // optional int32 rendered_width = 2;
  inline bool has_rendered_width() const;
  inline void clear_rendered_width();
  static const int kRenderedWidthFieldNumber = 2;
  inline ::google::protobuf::int32 rendered_width() const;
  inline void set_rendered_width(::google::protobuf::int32 value);

  // optional int32 rendered_height = 3;
  inline bool has_rendered_height() const;
  inline void clear_rendered_height();
  static const int kRenderedHeightFieldNumber = 3;
  inline ::google::protobuf::int32 rendered_height() const;
  inline void set_rendered_height(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:net_instaweb.RenderedImages.Image)
 private:
  inline void set_has_src();
  inline void clear_has_src();
  inline void set_has_rendered_width();
  inline void clear_has_rendered_width();
  inline void set_has_rendered_height();
  inline void clear_has_rendered_height();

  ::std::string* src_;
  ::google::protobuf::int32 rendered_width_;
  ::google::protobuf::int32 rendered_height_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();
  #endif
  friend void protobuf_AssignDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();
  friend void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();

  void InitAsDefaultInstance();
  static RenderedImages_Image* default_instance_;
};
// -------------------------------------------------------------------

class RenderedImages : public ::google::protobuf::MessageLite {
 public:
  RenderedImages();
  virtual ~RenderedImages();

  RenderedImages(const RenderedImages& from);

  inline RenderedImages& operator=(const RenderedImages& from) {
    CopyFrom(from);
    return *this;
  }

  static const RenderedImages& default_instance();

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  // Returns the internal default instance pointer. This function can
  // return NULL thus should not be used by the user. This is intended
  // for Protobuf internal code. Please use default_instance() declared
  // above instead.
  static inline const RenderedImages* internal_default_instance() {
    return default_instance_;
  }
  #endif

  void Swap(RenderedImages* other);

  // implements Message ----------------------------------------------

  RenderedImages* New() const;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from);
  void CopyFrom(const RenderedImages& from);
  void MergeFrom(const RenderedImages& from);
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

  typedef RenderedImages_Image Image;

  // accessors -------------------------------------------------------

  // repeated .net_instaweb.RenderedImages.Image image = 1;
  inline int image_size() const;
  inline void clear_image();
  static const int kImageFieldNumber = 1;
  inline const ::net_instaweb::RenderedImages_Image& image(int index) const;
  inline ::net_instaweb::RenderedImages_Image* mutable_image(int index);
  inline ::net_instaweb::RenderedImages_Image* add_image();
  inline const ::google::protobuf::RepeatedPtrField< ::net_instaweb::RenderedImages_Image >&
      image() const;
  inline ::google::protobuf::RepeatedPtrField< ::net_instaweb::RenderedImages_Image >*
      mutable_image();

  // @@protoc_insertion_point(class_scope:net_instaweb.RenderedImages)
 private:

  ::google::protobuf::RepeatedPtrField< ::net_instaweb::RenderedImages_Image > image_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  #ifdef GOOGLE_PROTOBUF_NO_STATIC_INITIALIZER
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto_impl();
  #else
  friend void  protobuf_AddDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();
  #endif
  friend void protobuf_AssignDesc_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();
  friend void protobuf_ShutdownFile_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto();

  void InitAsDefaultInstance();
  static RenderedImages* default_instance_;
};
// ===================================================================


// ===================================================================

// RenderedImages_Image

// optional string src = 1;
inline bool RenderedImages_Image::has_src() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RenderedImages_Image::set_has_src() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RenderedImages_Image::clear_has_src() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RenderedImages_Image::clear_src() {
  if (src_ != &::google::protobuf::internal::GetEmptyString()) {
    src_->clear();
  }
  clear_has_src();
}
inline const ::std::string& RenderedImages_Image::src() const {
  return *src_;
}
inline void RenderedImages_Image::set_src(const ::std::string& value) {
  set_has_src();
  if (src_ == &::google::protobuf::internal::GetEmptyString()) {
    src_ = new ::std::string;
  }
  src_->assign(value);
}
inline void RenderedImages_Image::set_src(const char* value) {
  set_has_src();
  if (src_ == &::google::protobuf::internal::GetEmptyString()) {
    src_ = new ::std::string;
  }
  src_->assign(value);
}
inline void RenderedImages_Image::set_src(const char* value, size_t size) {
  set_has_src();
  if (src_ == &::google::protobuf::internal::GetEmptyString()) {
    src_ = new ::std::string;
  }
  src_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* RenderedImages_Image::mutable_src() {
  set_has_src();
  if (src_ == &::google::protobuf::internal::GetEmptyString()) {
    src_ = new ::std::string;
  }
  return src_;
}
inline ::std::string* RenderedImages_Image::release_src() {
  clear_has_src();
  if (src_ == &::google::protobuf::internal::GetEmptyString()) {
    return NULL;
  } else {
    ::std::string* temp = src_;
    src_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyString());
    return temp;
  }
}
inline void RenderedImages_Image::set_allocated_src(::std::string* src) {
  if (src_ != &::google::protobuf::internal::GetEmptyString()) {
    delete src_;
  }
  if (src) {
    set_has_src();
    src_ = src;
  } else {
    clear_has_src();
    src_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyString());
  }
}

// optional int32 rendered_width = 2;
inline bool RenderedImages_Image::has_rendered_width() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void RenderedImages_Image::set_has_rendered_width() {
  _has_bits_[0] |= 0x00000002u;
}
inline void RenderedImages_Image::clear_has_rendered_width() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void RenderedImages_Image::clear_rendered_width() {
  rendered_width_ = 0;
  clear_has_rendered_width();
}
inline ::google::protobuf::int32 RenderedImages_Image::rendered_width() const {
  return rendered_width_;
}
inline void RenderedImages_Image::set_rendered_width(::google::protobuf::int32 value) {
  set_has_rendered_width();
  rendered_width_ = value;
}

// optional int32 rendered_height = 3;
inline bool RenderedImages_Image::has_rendered_height() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void RenderedImages_Image::set_has_rendered_height() {
  _has_bits_[0] |= 0x00000004u;
}
inline void RenderedImages_Image::clear_has_rendered_height() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void RenderedImages_Image::clear_rendered_height() {
  rendered_height_ = 0;
  clear_has_rendered_height();
}
inline ::google::protobuf::int32 RenderedImages_Image::rendered_height() const {
  return rendered_height_;
}
inline void RenderedImages_Image::set_rendered_height(::google::protobuf::int32 value) {
  set_has_rendered_height();
  rendered_height_ = value;
}

// -------------------------------------------------------------------

// RenderedImages

// repeated .net_instaweb.RenderedImages.Image image = 1;
inline int RenderedImages::image_size() const {
  return image_.size();
}
inline void RenderedImages::clear_image() {
  image_.Clear();
}
inline const ::net_instaweb::RenderedImages_Image& RenderedImages::image(int index) const {
  return image_.Get(index);
}
inline ::net_instaweb::RenderedImages_Image* RenderedImages::mutable_image(int index) {
  return image_.Mutable(index);
}
inline ::net_instaweb::RenderedImages_Image* RenderedImages::add_image() {
  return image_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::net_instaweb::RenderedImages_Image >&
RenderedImages::image() const {
  return image_;
}
inline ::google::protobuf::RepeatedPtrField< ::net_instaweb::RenderedImages_Image >*
RenderedImages::mutable_image() {
  return &image_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace net_instaweb

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_net_2finstaweb_2frewriter_2frendered_5fimage_2eproto__INCLUDED
