// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: scan_contexts.proto

#include "multisensor_localization/models/scan_context_manager/scan_contexts.pb.hpp"

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

namespace protobuf_scan_5fcontexts_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_scan_5fcontexts_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_ScanContext;
}  // namespace protobuf_scan_5fcontexts_2eproto
namespace scan_context_io {
class ScanContextDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ScanContext>
      _instance;
} _ScanContext_default_instance_;
class ScanContextsDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<ScanContexts>
      _instance;
} _ScanContexts_default_instance_;
}  // namespace scan_context_io
namespace protobuf_scan_5fcontexts_2eproto {
static void InitDefaultsScanContext() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::scan_context_io::_ScanContext_default_instance_;
    new (ptr) ::scan_context_io::ScanContext();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::scan_context_io::ScanContext::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_ScanContext =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsScanContext}, {}};

static void InitDefaultsScanContexts() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::scan_context_io::_ScanContexts_default_instance_;
    new (ptr) ::scan_context_io::ScanContexts();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::scan_context_io::ScanContexts::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_ScanContexts =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsScanContexts}, {
      &protobuf_scan_5fcontexts_2eproto::scc_info_ScanContext.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_ScanContext.base);
  ::google::protobuf::internal::InitSCC(&scc_info_ScanContexts.base);
}

::google::protobuf::Metadata file_level_metadata[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContext, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContext, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContext, data_),
  ~0u,
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContexts, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContexts, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContexts, num_rings_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContexts, num_sectors_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::scan_context_io::ScanContexts, data_),
  0,
  1,
  ~0u,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::scan_context_io::ScanContext)},
  { 7, 15, sizeof(::scan_context_io::ScanContexts)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::scan_context_io::_ScanContext_default_instance_),
  reinterpret_cast<const ::google::protobuf::Message*>(&::scan_context_io::_ScanContexts_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "scan_contexts.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\023scan_contexts.proto\022\017scan_context_io\"\033"
      "\n\013ScanContext\022\014\n\004data\030\001 \003(\002\"b\n\014ScanConte"
      "xts\022\021\n\tnum_rings\030\001 \002(\005\022\023\n\013num_sectors\030\002 "
      "\002(\005\022*\n\004data\030\003 \003(\0132\034.scan_context_io.Scan"
      "Context"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 167);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "scan_contexts.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_scan_5fcontexts_2eproto
namespace scan_context_io {

// ===================================================================

void ScanContext::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ScanContext::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ScanContext::ScanContext()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_scan_5fcontexts_2eproto::scc_info_ScanContext.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:scan_context_io.ScanContext)
}
ScanContext::ScanContext(const ScanContext& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      data_(from.data_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:scan_context_io.ScanContext)
}

void ScanContext::SharedCtor() {
}

ScanContext::~ScanContext() {
  // @@protoc_insertion_point(destructor:scan_context_io.ScanContext)
  SharedDtor();
}

void ScanContext::SharedDtor() {
}

void ScanContext::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ScanContext::descriptor() {
  ::protobuf_scan_5fcontexts_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scan_5fcontexts_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ScanContext& ScanContext::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_scan_5fcontexts_2eproto::scc_info_ScanContext.base);
  return *internal_default_instance();
}


void ScanContext::Clear() {
// @@protoc_insertion_point(message_clear_start:scan_context_io.ScanContext)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ScanContext::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:scan_context_io.ScanContext)
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
  // @@protoc_insertion_point(parse_success:scan_context_io.ScanContext)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:scan_context_io.ScanContext)
  return false;
#undef DO_
}

void ScanContext::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:scan_context_io.ScanContext)
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
  // @@protoc_insertion_point(serialize_end:scan_context_io.ScanContext)
}

::google::protobuf::uint8* ScanContext::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:scan_context_io.ScanContext)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated float data = 1;
  target = ::google::protobuf::internal::WireFormatLite::
    WriteFloatToArray(1, this->data_, target);

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:scan_context_io.ScanContext)
  return target;
}

size_t ScanContext::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:scan_context_io.ScanContext)
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

void ScanContext::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:scan_context_io.ScanContext)
  GOOGLE_DCHECK_NE(&from, this);
  const ScanContext* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ScanContext>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:scan_context_io.ScanContext)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:scan_context_io.ScanContext)
    MergeFrom(*source);
  }
}

void ScanContext::MergeFrom(const ScanContext& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:scan_context_io.ScanContext)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
}

void ScanContext::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:scan_context_io.ScanContext)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScanContext::CopyFrom(const ScanContext& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:scan_context_io.ScanContext)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScanContext::IsInitialized() const {
  return true;
}

void ScanContext::Swap(ScanContext* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ScanContext::InternalSwap(ScanContext* other) {
  using std::swap;
  data_.InternalSwap(&other->data_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ScanContext::GetMetadata() const {
  protobuf_scan_5fcontexts_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scan_5fcontexts_2eproto::file_level_metadata[kIndexInFileMessages];
}


// ===================================================================

void ScanContexts::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ScanContexts::kNumRingsFieldNumber;
const int ScanContexts::kNumSectorsFieldNumber;
const int ScanContexts::kDataFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ScanContexts::ScanContexts()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_scan_5fcontexts_2eproto::scc_info_ScanContexts.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:scan_context_io.ScanContexts)
}
ScanContexts::ScanContexts(const ScanContexts& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      data_(from.data_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&num_rings_, &from.num_rings_,
    static_cast<size_t>(reinterpret_cast<char*>(&num_sectors_) -
    reinterpret_cast<char*>(&num_rings_)) + sizeof(num_sectors_));
  // @@protoc_insertion_point(copy_constructor:scan_context_io.ScanContexts)
}

void ScanContexts::SharedCtor() {
  ::memset(&num_rings_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&num_sectors_) -
      reinterpret_cast<char*>(&num_rings_)) + sizeof(num_sectors_));
}

ScanContexts::~ScanContexts() {
  // @@protoc_insertion_point(destructor:scan_context_io.ScanContexts)
  SharedDtor();
}

void ScanContexts::SharedDtor() {
}

void ScanContexts::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* ScanContexts::descriptor() {
  ::protobuf_scan_5fcontexts_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scan_5fcontexts_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const ScanContexts& ScanContexts::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_scan_5fcontexts_2eproto::scc_info_ScanContexts.base);
  return *internal_default_instance();
}


void ScanContexts::Clear() {
// @@protoc_insertion_point(message_clear_start:scan_context_io.ScanContexts)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  data_.Clear();
  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 3u) {
    ::memset(&num_rings_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&num_sectors_) -
        reinterpret_cast<char*>(&num_rings_)) + sizeof(num_sectors_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool ScanContexts::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:scan_context_io.ScanContexts)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 num_rings = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          set_has_num_rings();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_rings_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // required int32 num_sectors = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          set_has_num_sectors();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &num_sectors_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .scan_context_io.ScanContext data = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
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
  // @@protoc_insertion_point(parse_success:scan_context_io.ScanContexts)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:scan_context_io.ScanContexts)
  return false;
#undef DO_
}

void ScanContexts::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:scan_context_io.ScanContexts)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 num_rings = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->num_rings(), output);
  }

  // required int32 num_sectors = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->num_sectors(), output);
  }

  // repeated .scan_context_io.ScanContext data = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->data_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3,
      this->data(static_cast<int>(i)),
      output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:scan_context_io.ScanContexts)
}

::google::protobuf::uint8* ScanContexts::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:scan_context_io.ScanContexts)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int32 num_rings = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->num_rings(), target);
  }

  // required int32 num_sectors = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->num_sectors(), target);
  }

  // repeated .scan_context_io.ScanContext data = 3;
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->data_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        3, this->data(static_cast<int>(i)), deterministic, target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:scan_context_io.ScanContexts)
  return target;
}

size_t ScanContexts::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:scan_context_io.ScanContexts)
  size_t total_size = 0;

  if (has_num_rings()) {
    // required int32 num_rings = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num_rings());
  }

  if (has_num_sectors()) {
    // required int32 num_sectors = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num_sectors());
  }

  return total_size;
}
size_t ScanContexts::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:scan_context_io.ScanContexts)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required int32 num_rings = 1;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num_rings());

    // required int32 num_sectors = 2;
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->num_sectors());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  // repeated .scan_context_io.ScanContext data = 3;
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

void ScanContexts::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:scan_context_io.ScanContexts)
  GOOGLE_DCHECK_NE(&from, this);
  const ScanContexts* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ScanContexts>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:scan_context_io.ScanContexts)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:scan_context_io.ScanContexts)
    MergeFrom(*source);
  }
}

void ScanContexts::MergeFrom(const ScanContexts& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:scan_context_io.ScanContexts)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  data_.MergeFrom(from.data_);
  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      num_rings_ = from.num_rings_;
    }
    if (cached_has_bits & 0x00000002u) {
      num_sectors_ = from.num_sectors_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void ScanContexts::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:scan_context_io.ScanContexts)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ScanContexts::CopyFrom(const ScanContexts& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:scan_context_io.ScanContexts)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ScanContexts::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;
  return true;
}

void ScanContexts::Swap(ScanContexts* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ScanContexts::InternalSwap(ScanContexts* other) {
  using std::swap;
  CastToBase(&data_)->InternalSwap(CastToBase(&other->data_));
  swap(num_rings_, other->num_rings_);
  swap(num_sectors_, other->num_sectors_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata ScanContexts::GetMetadata() const {
  protobuf_scan_5fcontexts_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_scan_5fcontexts_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace scan_context_io
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::scan_context_io::ScanContext* Arena::CreateMaybeMessage< ::scan_context_io::ScanContext >(Arena* arena) {
  return Arena::CreateInternal< ::scan_context_io::ScanContext >(arena);
}
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::scan_context_io::ScanContexts* Arena::CreateMaybeMessage< ::scan_context_io::ScanContexts >(Arena* arena) {
  return Arena::CreateInternal< ::scan_context_io::ScanContexts >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
