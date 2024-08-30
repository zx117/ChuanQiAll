
#pragma once
#include <cqdaq/data_descriptor_ptr.h>
#include <cqdaq/data_descriptor_builder_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>
#include <cqdaq/data_rule_factory.h>
#include <cqdaq/range_factory.h>
#include <coreobjects/unit_factory.h>
#include <cqdaq/scaling_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_data_descriptor
 * @addtogroup cqdaq_data_descriptor_factories Factories
 * @{
 */

/*!
 * @brief Data descriptor builder factory that creates a builder object with no parameters configured.
 */
inline DataDescriptorBuilderPtr DataDescriptorBuilder()
{
    DataDescriptorBuilderPtr obj(DataDescriptorBuilder_Create());
    return obj;
}

/*!
 * @brief Data descriptor copy factory that creates a Data descriptor builder object from a
 * different Data descriptor, copying its parameters.
 * @param descriptorToCopy The Data descriptor of which configuration should be copied.
 */
inline DataDescriptorBuilderPtr DataDescriptorBuilderCopy(const DataDescriptorPtr& dataDescriptor)
{
    DataDescriptorBuilderPtr obj(DataDescriptorBuilderFromExisting_Create(dataDescriptor));
    return obj;
}

/*!
 * @brief Creates a DataDescriptor using Builder
 * @param builder DataDescriptor Builder
 */
inline DataDescriptorPtr DataDescriptorFromBuilder(const DataDescriptorBuilderPtr& builder)
{
    DataDescriptorPtr obj(DataDescriptorFromBuilder_Create(builder));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Data descriptor struct.
 */
inline StructTypePtr DataDescriptorStructType()
{
    return StructType("dataDescriptor",
                      List<IString>("dimensions",
                                    "name",
                                    "sampleType",
                                    "unit",
                                    "valueRange",
                                    "dataRule",
                                    "scaling",
                                    "origin",
                                    "tickResolution",
                                    "structFields",
                                    "metadata"),
                      List<IBaseObject>(List<IDimension>(),
                                        "",
                                        0,
                                        nullptr,
                                        nullptr,
                                        ExplicitDataRule(),
                                        nullptr,
                                        nullptr,
                                        nullptr,
                                        nullptr,
                                        Dict<IString, IBaseObject>()),
                      List<IType>(SimpleType(ctList),
                                  SimpleType(ctString),
                                  SimpleType(ctInt),
                                  UnitStructType(),
                                  RangeStructType(),
                                  DataRuleStructType(),
                                  ScalingStructType(),
                                  SimpleType(ctString),
                                  RatioStructType(),
                                  SimpleType(ctList),
                                  SimpleType(ctDict)));
}

/*!@}*/

END_NAMESPACE_CQDAQ
