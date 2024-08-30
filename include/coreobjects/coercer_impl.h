
#pragma once
#include <coreobjects/coercer.h>
#include <coreobjects/eval_value_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class CoercerImpl final : public ImplementationOf<ICoercer, ISerializable>
{
public:
    explicit CoercerImpl(const StringPtr& evalStr);

    ErrCode INTERFACE_FUNC coerce(IBaseObject* propObj, IBaseObject* value, IBaseObject** result) override;
    ErrCode INTERFACE_FUNC getEval(IString** eval) override;
    
    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    FunctionPtr funcCoerce;
    EvalValuePtr evalValue;
    BaseObjectPtr value;
    StringPtr eval;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(CoercerImpl)

END_NAMESPACE_CQDAQ
