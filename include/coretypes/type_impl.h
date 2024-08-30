
#pragma once
#include <coretypes/intfs.h>
#include <coretypes/type_ptr.h>
#include <coretypes/baseobject_factory.h>
#include <utility>

BEGIN_NAMESPACE_CQDAQ

template <class TypeInterface>
class GenericTypeImpl : public ImplementationOf<TypeInterface, ISerializable, ICoreType>
{
public:
    explicit GenericTypeImpl (StringPtr typeName, CoreType coreType);

    ErrCode INTERFACE_FUNC getName(IString** typeName) override;
    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    virtual ErrCode INTERFACE_FUNC getCoreType(CoreType* coreType) override;

protected:
    StringPtr typeName;
    CoreType coreType;
};

using TypeImpl = GenericTypeImpl<IType>;


template <class TypeInterface>
GenericTypeImpl<TypeInterface>::GenericTypeImpl (StringPtr typeName, CoreType coreType)
    : typeName(std::move(typeName))
    , coreType(coreType)
{
}

template <class TypeInterface>
ErrCode GenericTypeImpl<TypeInterface>::getName(IString** typeName)
{
    if (!typeName)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *typeName = this->typeName.addRefAndReturn();
    return CQDAQ_SUCCESS;
}

template <class TypeInterface>
ErrCode GenericTypeImpl<TypeInterface>::equals(IBaseObject* other, Bool* equal) const
{
    if (equal == nullptr)
        return this->makeErrorInfo(CQDAQ_ERR_ARGUMENT_NULL, "Equals out-parameter must not be null");

    *equal = false;
    if (other == nullptr)
        return CQDAQ_SUCCESS;

    const TypePtr typeOther = BaseObjectPtr::Borrow(other).asPtrOrNull<IType>();
    if (typeOther == nullptr)
        return CQDAQ_SUCCESS;

    *equal = typeOther.getName() == this->typeName && this->coreType == typeOther.getCoreType();
    return CQDAQ_SUCCESS;
}

template <class TypeInterface>
ErrCode GenericTypeImpl<TypeInterface>::getCoreType(CoreType* coreType)
{
    if (!coreType)
        return CQDAQ_ERR_ARGUMENT_NULL;

    *coreType = this->coreType;
    return CQDAQ_SUCCESS;
}

END_NAMESPACE_CQDAQ
