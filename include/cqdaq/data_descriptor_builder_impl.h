
#pragma once
#include <coretypes/impl.h>
#include <coretypes/intfs.h>
#include <coretypes/listobject_factory.h>
#include <cqdaq/data_descriptor_builder_ptr.h>
#include <cqdaq/data_rule_calc.h>
#include <cqdaq/dimension_ptr.h>
#include <cqdaq/scaling_calc.h>

BEGIN_NAMESPACE_CQDAQ

class DataDescriptorBuilderImpl : public ImplementationOf<IDataDescriptorBuilder>
{
public:
    explicit DataDescriptorBuilderImpl();
    explicit DataDescriptorBuilderImpl(const DataDescriptorPtr& descriptorCopy);

    ErrCode INTERFACE_FUNC build(IDataDescriptor** dataDescriptor) override;

    ErrCode INTERFACE_FUNC setName(IString* name) override;
    ErrCode INTERFACE_FUNC getName(IString** name) override;

    ErrCode INTERFACE_FUNC setDimensions(IList* dimensions) override;
    ErrCode INTERFACE_FUNC getDimensions(IList** dimensions) override;

    ErrCode INTERFACE_FUNC setSampleType(SampleType sampleType) override;
    ErrCode INTERFACE_FUNC getSampleType(SampleType* sampleType) override;

    ErrCode INTERFACE_FUNC setUnit(IUnit* unit) override;
    ErrCode INTERFACE_FUNC getUnit(IUnit** unit) override;

    ErrCode INTERFACE_FUNC setValueRange(IRange* range) override;
    ErrCode INTERFACE_FUNC getValueRange(IRange** range) override;

    ErrCode INTERFACE_FUNC setRule(IDataRule* rule) override;
    ErrCode INTERFACE_FUNC getRule(IDataRule** rule) override;

    ErrCode INTERFACE_FUNC setOrigin(IString* origin) override;
    ErrCode INTERFACE_FUNC getOrigin(IString** origin) override;

    ErrCode INTERFACE_FUNC setTickResolution(IRatio* tickResolution) override;
    ErrCode INTERFACE_FUNC getTickResolution(IRatio** tickResolution) override;

    ErrCode INTERFACE_FUNC setPostScaling(IScaling* scaling) override;
    ErrCode INTERFACE_FUNC getPostScaling(IScaling** scaling) override;

    ErrCode INTERFACE_FUNC setMetadata(IDict* metadata) override;
    ErrCode INTERFACE_FUNC getMetadata(IDict** metadata) override;

    ErrCode INTERFACE_FUNC setStructFields(IList* structFields) override;
    ErrCode INTERFACE_FUNC getStructFields(IList** structFields) override;

protected:
    ListPtr<IDimension> dimensions;
    StringPtr name;
    SampleType sampleType;
    UnitPtr unit;
    RangePtr valueRange;
    DataRulePtr dataRule;
    ScalingPtr scaling;
    StringPtr origin;
    RatioPtr resolution;
    ListPtr<IDataDescriptor> structFields;
    DictPtr<IString, IString> metadata;
};

END_NAMESPACE_CQDAQ
