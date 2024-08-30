

/**
 * @file    anonymous_variable.h
 * @author  Martin Kraner
 * @date    04/03/2019
 * @version 1.0
 *
 * @brief Unique variable name generator.
 *        Each call returns a different identifier.
 *
 */
#pragma once

#define CONCATENATE_IMPL(s1, s2) s1##s2
#define CONCATENATE(s1, s2) CONCATENATE_IMPL(s1, s2)

#ifdef __COUNTER__
    #define ANONYMOUS_VARIABLE(str) \
        CONCATENATE(str, __COUNTER__)
#else
    #define ANONYMOUS_VARIABLE(str) \
        CONCATENATE(str, __LINE__)
#endif
