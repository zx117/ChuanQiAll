
#pragma once
#include <coretypes/listobject_factory.h>
#include <coretypes/struct_impl.h>
#include <cqdaq/data_descriptor_builder_ptr.h>
#include <cqdaq/data_descriptor_ptr.h>
#include <cqdaq/data_rule_calc.h>
#include <cqdaq/data_rule_calc_private.h>
#include <cqdaq/dimension_ptr.h>
#include <cqdaq/scaling_calc.h>
#include <cqdaq/scaling_calc_private.h>

BEGIN_NAMESPACE_CQDAQ

class DataDescriptorImpl : public GenericStructImpl<IDataDescriptor, IStruct, IScalingCalcPrivate, IDataRuleCalcPrivate>
{
public:
    explicit DataDescriptorImpl(IDataDescriptorBuilder* dataDescriptorBuilder);

    ErrCode INTERFACE_FUNC getName(IString** name) override;
    ErrCode INTERFACE_FUNC getDimensions(IList** dimensions) override;
    ErrCode INTERFACE_FUNC getSampleType(SampleType* sampleType) override;
    ErrCode INTERFACE_FUNC getUnit(IUnit** unit) override;
    ErrCode INTERFACE_FUNC getValueRange(IRange** range) override;
    ErrCode INTERFACE_FUNC getRule(IDataRule** rule) override;
    ErrCode INTERFACE_FUNC getOrigin(IString** origin) override;
    ErrCode INTERFACE_FUNC getTickResolution(IRatio** resolution) override;
    ErrCode INTERFACE_FUNC getPostScaling(IScaling** scaling) override;
    ErrCode INTERFACE_FUNC getMetadata(IDict** metadata) override;
    ErrCode INTERFACE_FUNC getStructFields(IList** structFields) override;
    ErrCode INTERFACE_FUNC getSampleSize(SizeT* sampleSize) override;
    ErrCode INTERFACE_FUNC getRawSampleSize(SizeT* rawSampleSizes) override;

    ErrCode INTERFACE_FUNC equals(IBaseObject* other, Bool* equal) const override;

    // IScalingCalcPrivate
    void* INTERFACE_FUNC scaleData(void* data, SizeT sampleCount) const override;
    void INTERFACE_FUNC scaleData(void* data, SizeT sampleCount, void** output) const override;
    bool INTERFACE_FUNC hasScalingCalc() const override;

    // IDataRuleCalcPrivate
    void* INTERFACE_FUNC calculateRule(const NumberPtr& packetOffset, SizeT sampleCount, void* input, SizeT inputSize) const override;
    void INTERFACE_FUNC calculateRule(const NumberPtr& packetOffset, SizeT sampleCount, void* input, SizeT inputSize, void** output) const override;
    bool INTERFACE_FUNC hasDataRuleCalc() const override;

    // ISerializable
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* /*context*/, IFunction* /*factoryCallback*/, IBaseObject** obj);

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

private:
    ErrCode validate();
    void initCalcs();
    std::unique_ptr<ScalingCalc> scalingCalc;
    std::unique_ptr<DataRuleCalc> dataRuleCalc;
    SizeT sampleSize;
    SizeT rawSampleSize;

    static DictPtr<IString, IBaseObject> PackBuilder(IDataDescriptorBuilder* dataDescriptorBuilder);
    void calculateSampleMemSize();
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(DataDescriptorImpl)

END_NAMESPACE_CQDAQ
