// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ring_keys.proto

#include "multisensor_mapping/models/scan_context_manager/ring_keys.pb.hpp"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_ring_5fkeys_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_ring_5fkeys_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_RingKey;
}  // namespace protobuf_ring_5fkeys_2eproto
namespace scan_context_io {
class RingKeyDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<RingKey>
      _instance;
} _RingKey_default_instance_;
class RingKeysDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<RingKeys>
      _instance;
} _RingKeys_default_instance_;
}  // namespace scan_context_io
namespace protobuf_ring_5fkeys_2eproto {
static void InitDefaultsRingKey() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::scan_context_io::_RingKey_default_instance_;
    new (ptr) ::scan_context_io::RingKey();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::scan_context_io::RingKey::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_RingKey =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsRingKey}, {}};

static void InitDefaultsRingKeys() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::scan_context_io::_RingKeys_default_instance_;
    new (ptr) ::scan_context_io::RingKeys();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::scan_context_io::RingKeys::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_RingKeys =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsRingKeys}, {
      &protobuf_ring_5fkeys_2eproto::scc_info_RingKey.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_RingKey.base);
  ::google::protobuf::internal::InitSCC(&scc_info_RingKeys.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::RingKey, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::RingKey, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::RingKey, data_),
  ~0u,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::RingKeys, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::RingKeys, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::RingKeys, data_),
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::scan_context_io::RingKey)},
  { 7, 13, sizeof(::scan_context_io::RingKeys)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::scan_context_io::_RingKey_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::scan_context_io::_RingKeys_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "ring_keys.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 2);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\017ring_keys.proto\022\017scan_context_io\"\027\n\007Ri"
      "ngKey\022\014\n\004data\030\001 \003(\002\"2\n\010RingKeys\022&\n\004data\030"
      "\001 \003(\0132\030.scan_context_io.RingKey"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 111);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ring_keys.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_ring_5fkeys_2eproto
namespace scan_context_io {

// ===================================================================

void RingKey::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RingKey::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RingKey::RingKey()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_ring_5fkeys_2eproto::scc_info_RingKey.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:scan_context_io.RingKey)
}
RingKey::RingKey(const RingKey& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      data_(from.data_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:scan_context_io.RingKey)
}

void RingKey::SharedCtor() {
}

RingKey::~RingKey() {
  // @@protoc_insertion_point(destructor:scan_context_io.RingKey)
  SharedDtor();
}

void RingKey::SharedDtor() {
}

void RingKey::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* RingKey::descriptor() {
  ::protobuf_ring_5fkeys_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ring_5fkeys_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RingKey& RingKey::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_ring_5fkeys_2eproto::scc_info_RingKey.base);
  return *internal_default_instance();
}


void RingKey::Clear() {
// @@protoc_insertion_point(message_clear_start:scan_context_io.RingKey)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool RingKey::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:scan_context_io.RingKey)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated float data = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(13u /* 13 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 1, 13u, input, this->mutable_data())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   float, ::google::protobuf::internal::WireFormatLite::TYPE_FLOAT>(
                 input, this->mutable_data())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:scan_context_io.RingKey)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:scan_context_io.RingKey)
  return false;
#undef DO_
}

void RingKey::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:scan_context_io.RingKey)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated float data = 1;
  for (int i = 0, n = this->data_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteFloat(
      1, this->data(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:scan_context_io.RingKey)
}

::google::protobuf::uint8* RingKey::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:scan_context_io.RingKey)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated float data = 1;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteFloatToArray(1, this->data_, target);

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:scan_context_io.RingKey)
  return target;
}

size_t RingKey::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:scan_context_io.RingKey)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated float data = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->data_size());
    size_t data_size = 4UL * count;
    total_size += 1 *
                  ::google::protobuf::internal::FromIntSize(this->data_size());
    total_size += data_size;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RingKey::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:scan_context_io.RingKey)
  GOOGLE_DCHECK_NE(&from, this);
  const RingKey* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RingKey>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:scan_context_io.RingKey)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:scan_context_io.RingKey)
    MergeFrom(*source);
  }
}

void RingKey::MergeFrom(const RingKey& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:scan_context_io.RingKey)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
}

void RingKey::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:scan_context_io.RingKey)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RingKey::CopyFrom(const RingKey& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:scan_context_io.RingKey)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RingKey::IsInitialized() const {
  return true;
}

void RingKey::Swap(RingKey* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RingKey::InternalSwap(RingKey* other) {
  using std::swap;
  data_.InternalSwap(&other->data_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata RingKey::GetMetadata() const {
  protobuf_ring_5fkeys_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ring_5fkeys_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void RingKeys::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int RingKeys::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

RingKeys::RingKeys()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_ring_5fkeys_2eproto::scc_info_RingKeys.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:scan_context_io.RingKeys)
}
RingKeys::RingKeys(const RingKeys& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      data_(from.data_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:scan_context_io.RingKeys)
}

void RingKeys::SharedCtor() {
}

RingKeys::~RingKeys() {
  // @@protoc_insertion_point(destructor:scan_context_io.RingKeys)
  SharedDtor();
}

void RingKeys::SharedDtor() {
}

void RingKeys::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* RingKeys::descriptor() {
  ::protobuf_ring_5fkeys_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ring_5fkeys_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const RingKeys& RingKeys::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_ring_5fkeys_2eproto::scc_info_RingKeys.base);
  return *internal_default_instance();
}


void RingKeys::Clear() {
// @@protoc_insertion_point(message_clear_start:scan_context_io.RingKeys)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool RingKeys::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:scan_context_io.RingKeys)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .scan_context_io.RingKey data = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(10u /* 10 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_data()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:scan_context_io.RingKeys)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:scan_context_io.RingKeys)
  return false;
#undef DO_
}

void RingKeys::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:scan_context_io.RingKeys)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .scan_context_io.RingKey data = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->data_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1,
      this->data(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:scan_context_io.RingKeys)
}

::google::protobuf::uint8* RingKeys::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:scan_context_io.RingKeys)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated .scan_context_io.RingKey data = 1;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->data_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        1, this->data(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:scan_context_io.RingKeys)
  return target;
}

size_t RingKeys::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:scan_context_io.RingKeys)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  // repeated .scan_context_io.RingKey data = 1;
  {
    unsigned int count = static_cast<unsigned int>(this->data_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->data(static_cast<int>(i)));
    }
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void RingKeys::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:scan_context_io.RingKeys)
  GOOGLE_DCHECK_NE(&from, this);
  const RingKeys* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const RingKeys>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:scan_context_io.RingKeys)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:scan_context_io.RingKeys)
    MergeFrom(*source);
  }
}

void RingKeys::MergeFrom(const RingKeys& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:scan_context_io.RingKeys)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
}

void RingKeys::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:scan_context_io.RingKeys)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RingKeys::CopyFrom(const RingKeys& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:scan_context_io.RingKeys)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RingKeys::IsInitialized() const {
  return true;
}

void RingKeys::Swap(RingKeys* other) {
  if (other == this) return;
  InternalSwap(other);
}
void RingKeys::InternalSwap(RingKeys* other) {
  using std::swap;
  CastToBase(&data_)->InternalSwap(CastToBase(&other->data_));
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata RingKeys::GetMetadata() const {
  protobuf_ring_5fkeys_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_ring_5fkeys_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace scan_context_io
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::scan_context_io::RingKey* Arena::CreateMaybeMessage< ::scan_context_io::RingKey >(Arena* arena) {
  return Arena::CreateInternal< ::scan_context_io::RingKey >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::scan_context_io::RingKeys* Arena::CreateMaybeMessage< ::scan_context_io::RingKeys >(Arena* arena) {
  return Arena::CreateInternal< ::scan_context_io::RingKeys >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
