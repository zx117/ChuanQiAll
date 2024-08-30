
#pragma once
#include <coretypes/dictobject_factory.h>
#include <coretypes/impl.h>
#include <coretypes/intfs.h>
#include <cqdaq/rule_private.h>
#include <cqdaq/scaling_builder.h>
#include <cqdaq/scaling_builder_ptr.h>
#include <cqdaq/scaling_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class ScalingBuilderImpl : public ImplementationOf<IScalingBuilder>
{
public:
    explicit ScalingBuilderImpl();
    explicit ScalingBuilderImpl(const ScalingPtr& scalingToCopy);

    explicit ScalingBuilderImpl(SampleType inputType,
                                ScaledSampleType outputType,
                                ScalingType ruleType,
                                DictPtr<IString, IBaseObject> params);

    explicit ScalingBuilderImpl(NumberPtr scale,
                                NumberPtr offset,
                                SampleType inputType,
                                ScaledSampleType outputType);

    ErrCode INTERFACE_FUNC build(IScaling** scaling) override;

    ErrCode INTERFACE_FUNC setInputDataType(SampleType type) override;
    ErrCode INTERFACE_FUNC getInputDataType(SampleType* type) override;

    ErrCode INTERFACE_FUNC setOutputDataType(ScaledSampleType type) override;
    ErrCode INTERFACE_FUNC getOutputDataType(ScaledSampleType* type) override;

    ErrCode INTERFACE_FUNC setScalingType(ScalingType type) override;
    ErrCode INTERFACE_FUNC getScalingType(ScalingType* type) override;

    ErrCode INTERFACE_FUNC setParameters(IDict* parameters) override;
    ErrCode INTERFACE_FUNC getParameters(IDict** parameters) override;
    ErrCode INTERFACE_FUNC addParameter(IString* name, IBaseObject* parameter) override;
    ErrCode INTERFACE_FUNC removeParameter(IString* name) override;

private:
    ScaledSampleType outputDataType;
    SampleType inputDataType;
    ScalingType ruleType;
    DictPtr<IString, IBaseObject> params;
};

END_NAMESPACE_CQDAQ
