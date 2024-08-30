
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <cqdaq/multi_reader.h>
#include <cqdaq/input_port.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_multi_reader Multi reader builder
 * @{
 */

/*!
 * @brief Builder component of Multi reader objects. Contains setter methods to configure the Multi reader parameters
 * and a `build` method that builds the Unit object.
 */
DECLARE_CQDAQ_INTERFACE(IMultiReaderBuilder, IBaseObject)
{
    /*!
     * @brief Builds and returns a Multi reader object using the currently set values of the Builder.
     * @param[out] multiReader The built Multi reader.
     */
    virtual ErrCode INTERFACE_FUNC build(IMultiReader** multiReader) = 0;

    // [returnSelf]
    /*!
     * @brief Adds the signal to list in multi reader
     * @param signal The signal which will be handled in multi reader
     */
    virtual ErrCode INTERFACE_FUNC addSignal(ISignal* signal) = 0;

    // [returnSelf]
    /*!
     * @brief Adds the input port to list in multi reader
     * @param port The input port which will be handled in multi reader
     */
    virtual ErrCode INTERFACE_FUNC addInputPort(IInputPort* port) = 0;

    // [templateType(ports, IComponent)]
    /*!
     * @brief Gets the list of input ports
     * @param[out] ports The list of input ports
     */
    virtual ErrCode INTERFACE_FUNC getSourceComponents(IList** ports) = 0;
   
    // [returnSelf]
    /*!
     * @brief Sets the value signal read type
     * @param type The value signal read type
     */
    virtual ErrCode INTERFACE_FUNC setValueReadType(SampleType type) = 0;

    /*!
     * @brief Gets the value signal read type
     * @param[out] type The value signal read type
     */
    virtual ErrCode INTERFACE_FUNC getValueReadType(SampleType* type) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the domain signal read type
     * @param type The domain signal read type
     */
    virtual ErrCode INTERFACE_FUNC setDomainReadType(SampleType type) = 0;

    /*!
     * @brief Gets the domain signal read type
     * @param[out] type The domain signal read type
     */
    virtual ErrCode INTERFACE_FUNC getDomainReadType(SampleType* type) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the read mode (Unscaled, Scaled, RawValue)
     * @param mode The read mode
     */
    virtual ErrCode INTERFACE_FUNC setReadMode(ReadMode mode) = 0;

    /*!
     * @brief Gets the read mode (Unscaled, Scaled, RawValue)
     * @param[out] mode The read mode
     */
    virtual ErrCode INTERFACE_FUNC getReadMode(ReadMode* mode) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the read timeout mode
     * @param mode The timeout mode. 
     * if "Any" returns immediatly if there is available data otherwise time-out is exceeded.
     * if "All" waiting until timeout and returns avaiable data if existing. otherwise time-out is exceeded.
     */
    virtual ErrCode INTERFACE_FUNC setReadTimeoutType(ReadTimeoutType type) = 0;

    /*!
     * @brief Gets the read timeout mode
     * @param mode The timeout mode. 
     * if "Any" returns immediatly if there is available data otherwise time-out is exceeded.
     * if "All" waiting until timeout and returns avaiable data if existing. otherwise time-out is exceeded.
     */
    virtual ErrCode INTERFACE_FUNC getReadTimeoutType(ReadTimeoutType* type) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the required common sample rate
     * @param sampleRate The required common sample rate
     */
    virtual ErrCode INTERFACE_FUNC setRequiredCommonSampleRate(Int sampleRate) = 0;

    /*!
     * @brief Gets the required common sample rate
     * @param sampleRate The required common sample rate
     */
    virtual ErrCode INTERFACE_FUNC getRequiredCommonSampleRate(Int* sampleRate) = 0;

    // [returnSelf]
    /*!
     * @brief Sets the start on full unit of domain
     * @param enabled enable/disable start on full unit of domain
     */
    virtual ErrCode INTERFACE_FUNC setStartOnFullUnitOfDomain(Bool enabled) = 0;

    /*!
     * @brief Gets the start on full unit of domain
     * @param enabled enable/disable start on full unit of domain
     */
    virtual ErrCode INTERFACE_FUNC getStartOnFullUnitOfDomain(Bool* enabled) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY_WITH_INTERFACE(LIBRARY_FACTORY, MultiReaderBuilder, IMultiReaderBuilder)

/*!@}*/
END_NAMESPACE_CQDAQ
