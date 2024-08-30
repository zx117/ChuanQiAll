
#pragma once
#include <cqdaq/tags_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_tags
 * @addtogroup cqdaq_tag_factories Factories
 * @{
 */

/*!
 * @brief Creates a new Tags object with an empty list of tags.
 */
inline TagsPtr Tags()
{
    return TagsPtr(Tags_Create());
}

/*!@}*/

END_NAMESPACE_CQDAQ
