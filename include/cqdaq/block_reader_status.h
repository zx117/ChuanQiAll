
#pragma once
#include <cqdaq/reader_status.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_readers
 * @addtogroup cqdaq_reader Block reader status
 * @{
 */

/*#
 * [interfaceSmartPtr(IReaderStatus, GenericReaderStatusPtr)]
 */

/*!
 * @brief IBlockReaderStatus inherits from IReaderStatus to expand information returned read function
 */
DECLARE_CQDAQ_INTERFACE(IBlockReaderStatus, IReaderStatus)
{
    /*!
     * @brief Returns the number of samples that were read. 
     * Sometimes, during the process of reading, an event packet may occur that stops the reading of remaining samples. 
     * Developers can use this function to determine how many samples were actually read.
     * @param[out] samplesCount the amount of samples that were read.
     */
    virtual ErrCode INTERFACE_FUNC getReadSamples(SizeT* readSamples) = 0;
};
/*!@}*/

CQDAQ_DECLARE_CLASS_FACTORY (
    LIBRARY_FACTORY, BlockReaderStatus,
    IEventPacket*, eventPacket,
    Bool, valid,
    SizeT, readSamples
)

END_NAMESPACE_CQDAQ