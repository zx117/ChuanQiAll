#ifndef __API_MESSAGE_IDS__
#define __API_MESSAGE_IDS__

#include <cstdint>

namespace cq
{

#define BASE_ID(name, value) const static std::uint64_t name = value;
#define MSG_ID(name, base, value, key, input, output, ret) const static std::uint64_t name = msg_base::base + value;
#define BEGIN_CATEGORIES() namespace msg_base {
#define END_CATEGORIES() }
#define BEGIN_GROUP(name) namespace name {
#define END_GROUP() }


#include "api_message_ids.inc"


#undef BASE_ID
#undef MSG_ID
#undef BEGIN_CATEGORIES
#undef END_CATEGORIES
#undef BEGIN_GROUP
#undef END_GROUP

}

#endif
