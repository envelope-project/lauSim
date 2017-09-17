// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: laik_ext.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "laik_ext.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
class laik_ext_msgDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<laik_ext_msg> {
} _laik_ext_msg_default_instance_;

namespace protobuf_laik_5fext_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];

}  // namespace

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTableField
    const TableStruct::entries[] = {
  {0, 0, 0, ::google::protobuf::internal::kInvalidMask, 0, 0},
};

PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::AuxillaryParseTableField
    const TableStruct::aux[] = {
  ::google::protobuf::internal::AuxillaryParseTableField(),
};
PROTOBUF_CONSTEXPR_VAR ::google::protobuf::internal::ParseTable const
    TableStruct::schema[] = {
  { NULL, NULL, 0, -1, -1, false },
};

const ::google::protobuf::uint32 TableStruct::offsets[] = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(laik_ext_msg, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(laik_ext_msg, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(laik_ext_msg, failing_nodes_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(laik_ext_msg, spare_nodes_),
  ~0u,
  ~0u,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 7, sizeof(laik_ext_msg)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_laik_ext_msg_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "laik_ext.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

}  // namespace

void TableStruct::Shutdown() {
  _laik_ext_msg_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _laik_ext_msg_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\016laik_ext.proto\":\n\014laik_ext_msg\022\025\n\rfail"
      "ing_nodes\030\002 \003(\t\022\023\n\013spare_nodes\030\004 \003(\t"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 76);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "laik_ext.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&TableStruct::Shutdown);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;

}  // namespace protobuf_laik_5fext_2eproto


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int laik_ext_msg::kFailingNodesFieldNumber;
const int laik_ext_msg::kSpareNodesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

laik_ext_msg::laik_ext_msg()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_laik_5fext_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:laik_ext_msg)
}
laik_ext_msg::laik_ext_msg(const laik_ext_msg& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0),
      failing_nodes_(from.failing_nodes_),
      spare_nodes_(from.spare_nodes_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  // @@protoc_insertion_point(copy_constructor:laik_ext_msg)
}

void laik_ext_msg::SharedCtor() {
  _cached_size_ = 0;
}

laik_ext_msg::~laik_ext_msg() {
  // @@protoc_insertion_point(destructor:laik_ext_msg)
  SharedDtor();
}

void laik_ext_msg::SharedDtor() {
}

void laik_ext_msg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* laik_ext_msg::descriptor() {
  protobuf_laik_5fext_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_laik_5fext_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const laik_ext_msg& laik_ext_msg::default_instance() {
  protobuf_laik_5fext_2eproto::InitDefaults();
  return *internal_default_instance();
}

laik_ext_msg* laik_ext_msg::New(::google::protobuf::Arena* arena) const {
  laik_ext_msg* n = new laik_ext_msg;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void laik_ext_msg::Clear() {
// @@protoc_insertion_point(message_clear_start:laik_ext_msg)
  failing_nodes_.Clear();
  spare_nodes_.Clear();
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool laik_ext_msg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:laik_ext_msg)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated string failing_nodes = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_failing_nodes()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->failing_nodes(this->failing_nodes_size() - 1).data(),
            this->failing_nodes(this->failing_nodes_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "laik_ext_msg.failing_nodes");
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated string spare_nodes = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_spare_nodes()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->spare_nodes(this->spare_nodes_size() - 1).data(),
            this->spare_nodes(this->spare_nodes_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "laik_ext_msg.spare_nodes");
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:laik_ext_msg)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:laik_ext_msg)
  return false;
#undef DO_
}

void laik_ext_msg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:laik_ext_msg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated string failing_nodes = 2;
  for (int i = 0, n = this->failing_nodes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->failing_nodes(i).data(), this->failing_nodes(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "laik_ext_msg.failing_nodes");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->failing_nodes(i), output);
  }

  // repeated string spare_nodes = 4;
  for (int i = 0, n = this->spare_nodes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->spare_nodes(i).data(), this->spare_nodes(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "laik_ext_msg.spare_nodes");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      4, this->spare_nodes(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:laik_ext_msg)
}

::google::protobuf::uint8* laik_ext_msg::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:laik_ext_msg)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // repeated string failing_nodes = 2;
  for (int i = 0, n = this->failing_nodes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->failing_nodes(i).data(), this->failing_nodes(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "laik_ext_msg.failing_nodes");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(2, this->failing_nodes(i), target);
  }

  // repeated string spare_nodes = 4;
  for (int i = 0, n = this->spare_nodes_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->spare_nodes(i).data(), this->spare_nodes(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "laik_ext_msg.spare_nodes");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(4, this->spare_nodes(i), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:laik_ext_msg)
  return target;
}

size_t laik_ext_msg::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:laik_ext_msg)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  // repeated string failing_nodes = 2;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->failing_nodes_size());
  for (int i = 0, n = this->failing_nodes_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->failing_nodes(i));
  }

  // repeated string spare_nodes = 4;
  total_size += 1 *
      ::google::protobuf::internal::FromIntSize(this->spare_nodes_size());
  for (int i = 0, n = this->spare_nodes_size(); i < n; i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->spare_nodes(i));
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void laik_ext_msg::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:laik_ext_msg)
  GOOGLE_DCHECK_NE(&from, this);
  const laik_ext_msg* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const laik_ext_msg>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:laik_ext_msg)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:laik_ext_msg)
    MergeFrom(*source);
  }
}

void laik_ext_msg::MergeFrom(const laik_ext_msg& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:laik_ext_msg)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  failing_nodes_.MergeFrom(from.failing_nodes_);
  spare_nodes_.MergeFrom(from.spare_nodes_);
}

void laik_ext_msg::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:laik_ext_msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void laik_ext_msg::CopyFrom(const laik_ext_msg& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:laik_ext_msg)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool laik_ext_msg::IsInitialized() const {
  return true;
}

void laik_ext_msg::Swap(laik_ext_msg* other) {
  if (other == this) return;
  InternalSwap(other);
}
void laik_ext_msg::InternalSwap(laik_ext_msg* other) {
  failing_nodes_.InternalSwap(&other->failing_nodes_);
  spare_nodes_.InternalSwap(&other->spare_nodes_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata laik_ext_msg::GetMetadata() const {
  protobuf_laik_5fext_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_laik_5fext_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// laik_ext_msg

// repeated string failing_nodes = 2;
int laik_ext_msg::failing_nodes_size() const {
  return failing_nodes_.size();
}
void laik_ext_msg::clear_failing_nodes() {
  failing_nodes_.Clear();
}
const ::std::string& laik_ext_msg::failing_nodes(int index) const {
  // @@protoc_insertion_point(field_get:laik_ext_msg.failing_nodes)
  return failing_nodes_.Get(index);
}
::std::string* laik_ext_msg::mutable_failing_nodes(int index) {
  // @@protoc_insertion_point(field_mutable:laik_ext_msg.failing_nodes)
  return failing_nodes_.Mutable(index);
}
void laik_ext_msg::set_failing_nodes(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:laik_ext_msg.failing_nodes)
  failing_nodes_.Mutable(index)->assign(value);
}
#if LANG_CXX11
void laik_ext_msg::set_failing_nodes(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:laik_ext_msg.failing_nodes)
  failing_nodes_.Mutable(index)->assign(std::move(value));
}
#endif
void laik_ext_msg::set_failing_nodes(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  failing_nodes_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:laik_ext_msg.failing_nodes)
}
void laik_ext_msg::set_failing_nodes(int index, const char* value, size_t size) {
  failing_nodes_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:laik_ext_msg.failing_nodes)
}
::std::string* laik_ext_msg::add_failing_nodes() {
  // @@protoc_insertion_point(field_add_mutable:laik_ext_msg.failing_nodes)
  return failing_nodes_.Add();
}
void laik_ext_msg::add_failing_nodes(const ::std::string& value) {
  failing_nodes_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:laik_ext_msg.failing_nodes)
}
#if LANG_CXX11
void laik_ext_msg::add_failing_nodes(::std::string&& value) {
  failing_nodes_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:laik_ext_msg.failing_nodes)
}
#endif
void laik_ext_msg::add_failing_nodes(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  failing_nodes_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:laik_ext_msg.failing_nodes)
}
void laik_ext_msg::add_failing_nodes(const char* value, size_t size) {
  failing_nodes_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:laik_ext_msg.failing_nodes)
}
const ::google::protobuf::RepeatedPtrField< ::std::string>&
laik_ext_msg::failing_nodes() const {
  // @@protoc_insertion_point(field_list:laik_ext_msg.failing_nodes)
  return failing_nodes_;
}
::google::protobuf::RepeatedPtrField< ::std::string>*
laik_ext_msg::mutable_failing_nodes() {
  // @@protoc_insertion_point(field_mutable_list:laik_ext_msg.failing_nodes)
  return &failing_nodes_;
}

// repeated string spare_nodes = 4;
int laik_ext_msg::spare_nodes_size() const {
  return spare_nodes_.size();
}
void laik_ext_msg::clear_spare_nodes() {
  spare_nodes_.Clear();
}
const ::std::string& laik_ext_msg::spare_nodes(int index) const {
  // @@protoc_insertion_point(field_get:laik_ext_msg.spare_nodes)
  return spare_nodes_.Get(index);
}
::std::string* laik_ext_msg::mutable_spare_nodes(int index) {
  // @@protoc_insertion_point(field_mutable:laik_ext_msg.spare_nodes)
  return spare_nodes_.Mutable(index);
}
void laik_ext_msg::set_spare_nodes(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:laik_ext_msg.spare_nodes)
  spare_nodes_.Mutable(index)->assign(value);
}
#if LANG_CXX11
void laik_ext_msg::set_spare_nodes(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:laik_ext_msg.spare_nodes)
  spare_nodes_.Mutable(index)->assign(std::move(value));
}
#endif
void laik_ext_msg::set_spare_nodes(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  spare_nodes_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:laik_ext_msg.spare_nodes)
}
void laik_ext_msg::set_spare_nodes(int index, const char* value, size_t size) {
  spare_nodes_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:laik_ext_msg.spare_nodes)
}
::std::string* laik_ext_msg::add_spare_nodes() {
  // @@protoc_insertion_point(field_add_mutable:laik_ext_msg.spare_nodes)
  return spare_nodes_.Add();
}
void laik_ext_msg::add_spare_nodes(const ::std::string& value) {
  spare_nodes_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:laik_ext_msg.spare_nodes)
}
#if LANG_CXX11
void laik_ext_msg::add_spare_nodes(::std::string&& value) {
  spare_nodes_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:laik_ext_msg.spare_nodes)
}
#endif
void laik_ext_msg::add_spare_nodes(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  spare_nodes_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:laik_ext_msg.spare_nodes)
}
void laik_ext_msg::add_spare_nodes(const char* value, size_t size) {
  spare_nodes_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:laik_ext_msg.spare_nodes)
}
const ::google::protobuf::RepeatedPtrField< ::std::string>&
laik_ext_msg::spare_nodes() const {
  // @@protoc_insertion_point(field_list:laik_ext_msg.spare_nodes)
  return spare_nodes_;
}
::google::protobuf::RepeatedPtrField< ::std::string>*
laik_ext_msg::mutable_spare_nodes() {
  // @@protoc_insertion_point(field_mutable_list:laik_ext_msg.spare_nodes)
  return &spare_nodes_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)