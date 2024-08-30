
#pragma once

#include <coreobjects/property_ptr.h>

#include <optional>
#include <unordered_set>

BEGIN_NAMESPACE_CQDAQ

class PropertyWrapperImpl : public ImplementationOf<IProperty>
{
public:
    PropertyWrapperImpl(const PropertyPtr& property, std::optional<std::unordered_set<size_t>> allowedSelectionValues);

    virtual ErrCode INTERFACE_FUNC getValueType(CoreType* type);
    virtual ErrCode INTERFACE_FUNC getKeyType(CoreType* type);
    virtual ErrCode INTERFACE_FUNC getItemType(CoreType* type);
    virtual ErrCode INTERFACE_FUNC getName(IString** name);
    virtual ErrCode INTERFACE_FUNC getDescription(IString** description);
    virtual ErrCode INTERFACE_FUNC getUnit(IUnit** unit);
    virtual ErrCode INTERFACE_FUNC getMinValue(INumber** min);
    virtual ErrCode INTERFACE_FUNC getMaxValue(INumber** max);
    virtual ErrCode INTERFACE_FUNC getDefaultValue(IBaseObject** value);
    // [templateType(values, IBaseObject)]
    virtual ErrCode INTERFACE_FUNC getSuggestedValues(IList** values);
    virtual ErrCode INTERFACE_FUNC getVisible(Bool* visible);
    virtual ErrCode INTERFACE_FUNC getReadOnly(Bool* readOnly);
    virtual ErrCode INTERFACE_FUNC getSelectionValues(IBaseObject** values);
    virtual ErrCode INTERFACE_FUNC getReferencedProperty(IProperty** property);
    virtual ErrCode INTERFACE_FUNC getIsReferenced(Bool* isReferenced);
    virtual ErrCode INTERFACE_FUNC getValidator(IValidator** validator);
    virtual ErrCode INTERFACE_FUNC getCoercer(ICoercer** coercer);
    virtual ErrCode INTERFACE_FUNC getCallableInfo(ICallableInfo** callable);
    virtual ErrCode INTERFACE_FUNC getStructType(IStructType** structType);
    // [ignore(Wrapper)]
    virtual ErrCode INTERFACE_FUNC getOnPropertyValueWrite(IEvent** event);
    // [ignore(Wrapper)]
    virtual ErrCode INTERFACE_FUNC getOnPropertyValueRead(IEvent** event);

private:
    PropertyPtr property;
    std::optional<std::unordered_set<size_t>> allowedSelectionValues;
};

END_NAMESPACE_CQDAQ
