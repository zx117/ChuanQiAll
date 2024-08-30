
#pragma once
#include <cqdaq/reader.h>
#include <cqdaq/input_port_config.h>
#include <cqdaq/sample_type.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_reader_config Reader config
 * @{
 */

/*#
 * [include(IReader)]
 */
/*!
 * @brief An interface providing access to a new reader in order to reuse the invalidated reader's settings and configuration.
 */
DECLARE_CQDAQ_INTERFACE(IReaderConfig, IBaseObject)
{
    /*!
     * @brief Gets the transform function that will be called with the read value-data and currently valid Signal-Descriptor
     * giving the user the chance add a custom post-processing step.
     * @param[out] transform The function performing the post-processing or @c nullptr if not assigned.
     */
    virtual ErrCode INTERFACE_FUNC getValueTransformFunction(IFunction** transform) = 0;

    /*!
     * @brief Gets the transform function that will be called with the read domain-data and currently valid Signal-Descriptor
     * giving the user the chance add a custom post-processing step.
     * @param[out] transform The function performing the post-processing or @c nullptr if not assigned.
     */
    virtual ErrCode INTERFACE_FUNC getDomainTransformFunction(IFunction** transform) = 0;

    // [templateType(ports, IInputPortConfig)]
    /*!
     * @brief Gets the internally created input-ports if used.
     * @param[out] ports The internal Input-Ports if used by the reader otherwise @c nullptr.
     */
    virtual ErrCode INTERFACE_FUNC getInputPorts(IList** ports) = 0;

    /*!
     * @brief Gets the type of time-out handling used by the reader.
     * @param[out] timeoutType How the reader handles time-outs.
     */
    virtual ErrCode INTERFACE_FUNC getReadTimeoutType(ReadTimeoutType* timeoutType) = 0;

    /*!
     * @brief Marks the current reader as invalid preventing any additional operations to be performed on the reader
     * except reusing its info and configuration in a new reader.
     */
    virtual ErrCode INTERFACE_FUNC markAsInvalid() = 0;
};

END_NAMESPACE_CQDAQ
