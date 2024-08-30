
#pragma once
#include <coretypes/stringobject.h>
#include <coretypes/intfs.h>
#include <coretypes/convertible.h>
#include <coretypes/coretype.h>
#include <coretypes/comparable.h>
#include <coretypes/serializable.h>

BEGIN_NAMESPACE_CQDAQ

class StringImpl : public ImplementationOf<IString, IConvertible, ICoreType, IComparable, ISerializable>
{
public:
    StringImpl(ConstCharPtr str);
    StringImpl(ConstCharPtr data, SizeT length);

    ~StringImpl() override;

    // IBaseObject
    ErrCode INTERFACE_FUNC getHashCode(SizeT* hashCode) override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;
    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    // IString
    ErrCode INTERFACE_FUNC getCharPtr(ConstCharPtr* value) override;
    ErrCode INTERFACE_FUNC getLength(SizeT* size) override;

    // IConvertible
    ErrCode INTERFACE_FUNC toFloat(Float* val) override;
    ErrCode INTERFACE_FUNC toInt(Int* val) override;
    ErrCode INTERFACE_FUNC toBool(Bool* val) override;

    // ICoreType
    ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

    // IComparable
    ErrCode INTERFACE_FUNC compareTo(IBaseObject* obj) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

private:
    char* str;
    SizeT hashCode;
    bool hashCalculated;
};

END_NAMESPACE_CQDAQ
