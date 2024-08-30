
#pragma once
#include <coreobjects/validator.h>
#include <coreobjects/eval_value_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ValidatorImpl final : public ImplementationOf<IValidator, ISerializable>
{
public:
    explicit ValidatorImpl(const StringPtr& evalStr);

    ErrCode INTERFACE_FUNC validate(IBaseObject* propObj, IBaseObject* value) override;
    ErrCode INTERFACE_FUNC getEval(IString** eval) override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    ProcedurePtr procValidate;
    EvalValuePtr evalValue;
    BaseObjectPtr value;
    StringPtr eval;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ValidatorImpl)

END_NAMESPACE_CQDAQ
