
#pragma once
#include <coretypes/serializer.h>
#include <coretypes/intfs.h>
#include <rapidjson/writer.h>
#include <rapidjson/prettywriter.h>
#include <coretypes/deserializer.h>

BEGIN_NAMESPACE_CQDAQ

template <typename TWriter = rapidjson::Writer<rapidjson::StringBuffer>>
class JsonSerializerImpl : public ImplementationOf<ISerializer>
{
public:
    JsonSerializerImpl();

    ErrCode INTERFACE_FUNC startList() override;
    ErrCode INTERFACE_FUNC endList() override;

    ErrCode INTERFACE_FUNC getOutput(IString** output) override;

    ErrCode INTERFACE_FUNC keyStr(IString* name) override;
    ErrCode INTERFACE_FUNC key(ConstCharPtr string) override;
    ErrCode INTERFACE_FUNC keyRaw(ConstCharPtr string, SizeT length) override;

    ErrCode INTERFACE_FUNC writeInt(Int integer) override;
    ErrCode INTERFACE_FUNC writeBool(Bool boolean) override;
    ErrCode INTERFACE_FUNC writeFloat(Float real) override;
    ErrCode INTERFACE_FUNC writeNull() override;

    ErrCode INTERFACE_FUNC reset() override;

    ErrCode INTERFACE_FUNC isComplete(Bool* complete) override;

    ErrCode INTERFACE_FUNC startTaggedObject(ISerializable* serializable) override;
    ErrCode INTERFACE_FUNC startObject() override;

    template <typename TSerializable>
    ErrCode startTaggedObject(TSerializable* obj);

    ErrCode INTERFACE_FUNC endObject() override;
    ErrCode INTERFACE_FUNC writeString(ConstCharPtr string, SizeT length) override;

protected:
    rapidjson::StringBuffer buffer;
    TWriter writer;
};

template <typename TWriter>
template <typename TSerializable>
ErrCode JsonSerializerImpl<TWriter>::startTaggedObject(TSerializable* obj)
{
    writer.StartObject();
    writer.Key("__type");
    writer.Int(TSerializable::serializeId());

    return CQDAQ_SUCCESS;
}

using PrettyJsonSerializer = JsonSerializerImpl<rapidjson::PrettyWriter<rapidjson::StringBuffer>>;

END_NAMESPACE_CQDAQ
