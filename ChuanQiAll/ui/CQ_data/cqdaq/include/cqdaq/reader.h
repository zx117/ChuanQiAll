
#pragma once
#include <coretypes/procedure.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_reader Reader
 * @{
 */

/*!
 * @brief Controls how Reader read call time-outs are handled.
 */
enum class ReadTimeoutType
{
    Any, /*!< When some segments are available return them immediately.
          *   When no segments are available return immediately when any arrive or time-out is exceeded.
          */
    All  /*!< Wait for the requested amount or until time-out is exceeded.*/
};

/*#
 * [templated(defaultAliasName: ReaderPtr)]
 * [interfaceSmartPtr(IReader, GenericReaderPtr)]
 */

/*!
 * @brief A basic signal reader that simplifies accessing the signals's data stream.
 */
DECLARE_CQDAQ_INTERFACE(IReader, IBaseObject)
{
    /*!
     * @brief Gets the number of segments available to read
     * @param[out] count The number of available segments
     */
    virtual ErrCode INTERFACE_FUNC getAvailableCount(SizeT* count) = 0;

    /*!
     * @brief Sets the specified callback function to be called when there is available data in the reader.
     * Pass @c nullptr to unset the callback. The callback should take no arguments.
     * @param callback The callback function to be set or @c nullptr to unset it.
     */
    virtual ErrCode INTERFACE_FUNC setOnDataAvailable(IProcedure* callback) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
