
#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_logger
 * @addtogroup cqdaq_logger_thread_pool Logger thread pool
 * @{
 */

/*!
 * @brief Container for messages queue and backing threads used for asynchronous logging.
 */
DECLARE_CQDAQ_INTERFACE(ILoggerThreadPool, IBaseObject)
{
};

/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY(LIBRARY_FACTORY, LoggerThreadPool)

END_NAMESPACE_CQDAQ
