
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_scheduler_components
 * @addtogroup cqdaq_graph_visualization GraphVisualization
 * @{
 */

/*!
 * @brief Represents a way to get a string representation of a graph
 * usually in some diagram description language like DOT, mermaid or D2.
 */
DECLARE_CQDAQ_INTERFACE(IGraphVisualization, IBaseObject)
{
    /*!
     * @brief Returns the graph representation as a string.
     * @param[out] dot Graph's string representation
     */
    virtual ErrCode INTERFACE_FUNC dump(IString** dot) = 0;
};
/*!@}*/

END_NAMESPACE_CQDAQ
