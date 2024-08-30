
#pragma once
#include <cqdaq/signal_config_ptr.h>
#include <cqdaq/context_ptr.h>
#include <cqdaq/data_descriptor_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_signal
 * @addtogroup cqdaq_signal_factories Factories
 * @{
 */

/*!
 * @brief Creates a new Signal with a given Context and Descriptor, as well as an optional uniqueId.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Signal.
 * @param descriptor The Signal-descriptor.
 * @param parent <description-missing>
 * @param localId <description-missing>
 * @param className <description-missing>
 */
inline SignalConfigPtr SignalWithDescriptor(const ContextPtr& context,
                                            const DataDescriptorPtr& descriptor,
                                            const ComponentPtr& parent,
                                            const StringPtr& localId,
                                            const StringPtr& className = nullptr)
{
    SignalConfigPtr obj(SignalWithDescriptor_Create(context, descriptor, parent, localId, className));
    return obj;
}

/*!
 * @brief Creates a new Signal with a given Context, as well as an optional uniqueId. The created Signal has no Descriptor.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Signal.
 * @param parent <description-missing>
 * @param localId <description-missing>
 * @param className <description-missing>
 */
inline SignalConfigPtr Signal(const ContextPtr& context,
                              const ComponentPtr& parent,
                              const StringPtr& localId,
                              const StringPtr& className = nullptr)
{
    SignalConfigPtr obj(Signal_Create(context, parent, localId, className));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
