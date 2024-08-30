#pragma once

#include <cassert>

#define CQ_ASSERT(condition) assert(condition)

#define CQ_ASSERT_EQUAL(val1, val2) assert(val1 == val2)

#define CQ_ASSERT_LT(val1, val2) assert(val1 < val2)

#define CQ_ASSERT_LTE(val1, val2) assert(val1 <= val2)

#define CQ_ASSERT_GT(val1, val2) assert(val1 > val2)

#define CQ_ASSERT_GTE(val1, val2) assert(val1 >= val2)

#define CQ_ASSERT_MSG(condition, msg, ...) assert(condition)

#define CQ_ASSERT_FAIL(msg, ...) assert(false)

#define CQ_VERIFY(condition) \
    (void)(condition);

#define CQ_VERIFY_MSG(condition, msg, ...) \
    (void)(condition);
