
#pragma once
#include <cqdaq/scaling.h>
#include <cqdaq/rule_private.h>
#include <coretypes/struct_impl.h>
#include <coretypes/dictobject_factory.h>
#include <cqdaq/scaling_builder_ptr.h>
#include <cqdaq/scaling_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ScalingImpl : public GenericStructImpl<IScaling, IStruct, IRulePrivate>
{
public:
    explicit ScalingImpl(SampleType inputType,
                         ScaledSampleType outputType,
                         ScalingType ruleType,
                         DictPtr<IString, IBaseObject> params);

    explicit ScalingImpl(NumberPtr scale,
                         NumberPtr offset,
                         SampleType inputType,
                         ScaledSampleType outputType);

    explicit ScalingImpl(IScalingBuilder* scalingBuilder);

    ErrCode INTERFACE_FUNC getInputSampleType(SampleType* type) override;
    ErrCode INTERFACE_FUNC getOutputSampleType(ScaledSampleType* type) override;

    ErrCode INTERFACE_FUNC getType(ScalingType* type) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;

    ErrCode INTERFACE_FUNC verifyParameters() override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equals) const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

private:
    ErrCode verifyParametersInternal() const;
    static DictPtr<IString, IBaseObject> PackBuilder(IScalingBuilder* scalingBuilder);

    ScaledSampleType outputDataType;
    SampleType inputDataType;
    ScalingType ruleType;
    DictPtr<IString, IBaseObject> params;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(ScalingImpl)

END_NAMESPACE_CQDAQ
