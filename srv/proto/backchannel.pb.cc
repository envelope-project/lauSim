// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: backchannel.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "backchannel.pb.h"

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
class BackchannelDefaultTypeInternal : public ::google::protobuf::internal::ExplicitlyConstructed<Backchannel> {
} _Backchannel_default_instance_;

namespace protobuf_backchannel_2eproto {


namespace {

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

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
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Backchannel, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Backchannel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Backchannel, type_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Backchannel, logerrmsg_),
  1,
  0,
};

static const ::google::protobuf::internal::MigrationSchema schemas[] = {
  { 0, 7, sizeof(Backchannel)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&_Backchannel_default_instance_),
};

namespace {

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "backchannel.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      file_level_metadata, file_level_enum_descriptors, NULL);
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
  _Backchannel_default_instance_.Shutdown();
  delete file_level_metadata[0].reflection;
}

void TableStruct::InitDefaultsImpl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::internal::InitProtobufDefaults();
  _Backchannel_default_instance_.DefaultConstruct();
}

void InitDefaults() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &TableStruct::InitDefaultsImpl);
}
void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] = {
      "\n\021backchannel.proto\"c\n\013Backchannel\022\"\n\004ty"
      "pe\030\001 \002(\0162\024.Backchannel.MsgType\022\021\n\tLogErr"
      "Msg\030\002 \001(\t\"\035\n\007MsgType\022\007\n\003LOG\020\000\022\t\n\005ERROR\020\001"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 120);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "backchannel.proto", &protobuf_RegisterTypes);
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

}  // namespace protobuf_backchannel_2eproto

const ::google::protobuf::EnumDescriptor* Backchannel_MsgType_descriptor() {
  protobuf_backchannel_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_backchannel_2eproto::file_level_enum_descriptors[0];
}
bool Backchannel_MsgType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const Backchannel_MsgType Backchannel::LOG;
const Backchannel_MsgType Backchannel::ERROR;
const Backchannel_MsgType Backchannel::MsgType_MIN;
const Backchannel_MsgType Backchannel::MsgType_MAX;
const int Backchannel::MsgType_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Backchannel::kTypeFieldNumber;
const int Backchannel::kLogErrMsgFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Backchannel::Backchannel()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (GOOGLE_PREDICT_TRUE(this != internal_default_instance())) {
    protobuf_backchannel_2eproto::InitDefaults();
  }
  SharedCtor();
  // @@protoc_insertion_point(constructor:Backchannel)
}
Backchannel::Backchannel(const Backchannel& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_),
      _cached_size_(0) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  logerrmsg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.has_logerrmsg()) {
    logerrmsg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.logerrmsg_);
  }
  type_ = from.type_;
  // @@protoc_insertion_point(copy_constructor:Backchannel)
}

void Backchannel::SharedCtor() {
  _cached_size_ = 0;
  logerrmsg_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  type_ = 0;
}

Backchannel::~Backchannel() {
  // @@protoc_insertion_point(destructor:Backchannel)
  SharedDtor();
}

void Backchannel::SharedDtor() {
  logerrmsg_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Backchannel::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Backchannel::descriptor() {
  protobuf_backchannel_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_backchannel_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Backchannel& Backchannel::default_instance() {
  protobuf_backchannel_2eproto::InitDefaults();
  return *internal_default_instance();
}

Backchannel* Backchannel::New(::google::protobuf::Arena* arena) const {
  Backchannel* n = new Backchannel;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Backchannel::Clear() {
// @@protoc_insertion_point(message_clear_start:Backchannel)
  if (has_logerrmsg()) {
    GOOGLE_DCHECK(!logerrmsg_.IsDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited()));
    (*logerrmsg_.UnsafeRawStringPointer())->clear();
  }
  type_ = 0;
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool Backchannel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:Backchannel)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .Backchannel.MsgType type = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::Backchannel_MsgType_IsValid(value)) {
            set_type(static_cast< ::Backchannel_MsgType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional string LogErrMsg = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(18u)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_logerrmsg()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->logerrmsg().data(), this->logerrmsg().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "Backchannel.LogErrMsg");
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
  // @@protoc_insertion_point(parse_success:Backchannel)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:Backchannel)
  return false;
#undef DO_
}

void Backchannel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:Backchannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .Backchannel.MsgType type = 1;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->type(), output);
  }

  // optional string LogErrMsg = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->logerrmsg().data(), this->logerrmsg().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Backchannel.LogErrMsg");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->logerrmsg(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:Backchannel)
}

::google::protobuf::uint8* Backchannel::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:Backchannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required .Backchannel.MsgType type = 1;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->type(), target);
  }

  // optional string LogErrMsg = 2;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->logerrmsg().data(), this->logerrmsg().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "Backchannel.LogErrMsg");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->logerrmsg(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Backchannel)
  return target;
}

size_t Backchannel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Backchannel)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  // required .Backchannel.MsgType type = 1;
  if (has_type()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
  }
  // optional string LogErrMsg = 2;
  if (has_logerrmsg()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->logerrmsg());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Backchannel::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:Backchannel)
  GOOGLE_DCHECK_NE(&from, this);
  const Backchannel* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Backchannel>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:Backchannel)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:Backchannel)
    MergeFrom(*source);
  }
}

void Backchannel::MergeFrom(const Backchannel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:Backchannel)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 3u) {
    if (cached_has_bits & 0x00000001u) {
      set_has_logerrmsg();
      logerrmsg_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.logerrmsg_);
    }
    if (cached_has_bits & 0x00000002u) {
      type_ = from.type_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void Backchannel::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:Backchannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Backchannel::CopyFrom(const Backchannel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Backchannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Backchannel::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000002) != 0x00000002) return false;
  return true;
}

void Backchannel::Swap(Backchannel* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Backchannel::InternalSwap(Backchannel* other) {
  logerrmsg_.Swap(&other->logerrmsg_);
  std::swap(type_, other->type_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Backchannel::GetMetadata() const {
  protobuf_backchannel_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_backchannel_2eproto::file_level_metadata[kIndexInFileMessages];
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Backchannel

// required .Backchannel.MsgType type = 1;
bool Backchannel::has_type() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
void Backchannel::set_has_type() {
  _has_bits_[0] |= 0x00000002u;
}
void Backchannel::clear_has_type() {
  _has_bits_[0] &= ~0x00000002u;
}
void Backchannel::clear_type() {
  type_ = 0;
  clear_has_type();
}
::Backchannel_MsgType Backchannel::type() const {
  // @@protoc_insertion_point(field_get:Backchannel.type)
  return static_cast< ::Backchannel_MsgType >(type_);
}
void Backchannel::set_type(::Backchannel_MsgType value) {
  assert(::Backchannel_MsgType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:Backchannel.type)
}

// optional string LogErrMsg = 2;
bool Backchannel::has_logerrmsg() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void Backchannel::set_has_logerrmsg() {
  _has_bits_[0] |= 0x00000001u;
}
void Backchannel::clear_has_logerrmsg() {
  _has_bits_[0] &= ~0x00000001u;
}
void Backchannel::clear_logerrmsg() {
  logerrmsg_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_logerrmsg();
}
const ::std::string& Backchannel::logerrmsg() const {
  // @@protoc_insertion_point(field_get:Backchannel.LogErrMsg)
  return logerrmsg_.GetNoArena();
}
void Backchannel::set_logerrmsg(const ::std::string& value) {
  set_has_logerrmsg();
  logerrmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:Backchannel.LogErrMsg)
}
#if LANG_CXX11
void Backchannel::set_logerrmsg(::std::string&& value) {
  set_has_logerrmsg();
  logerrmsg_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:Backchannel.LogErrMsg)
}
#endif
void Backchannel::set_logerrmsg(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  set_has_logerrmsg();
  logerrmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:Backchannel.LogErrMsg)
}
void Backchannel::set_logerrmsg(const char* value, size_t size) {
  set_has_logerrmsg();
  logerrmsg_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:Backchannel.LogErrMsg)
}
::std::string* Backchannel::mutable_logerrmsg() {
  set_has_logerrmsg();
  // @@protoc_insertion_point(field_mutable:Backchannel.LogErrMsg)
  return logerrmsg_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Backchannel::release_logerrmsg() {
  // @@protoc_insertion_point(field_release:Backchannel.LogErrMsg)
  clear_has_logerrmsg();
  return logerrmsg_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Backchannel::set_allocated_logerrmsg(::std::string* logerrmsg) {
  if (logerrmsg != NULL) {
    set_has_logerrmsg();
  } else {
    clear_has_logerrmsg();
  }
  logerrmsg_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), logerrmsg);
  // @@protoc_insertion_point(field_set_allocated:Backchannel.LogErrMsg)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)