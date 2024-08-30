#pragma once

#ifdef _MSVC_LANG
#  define CQ_CPLUSPLUS _MSVC_LANG
#else
#  define CQ_CPLUSPLUS __cplusplus
#endif

#define CQ_UNUSED(expr) do { (void)(expr); } while (0)

#if CQ_CPLUSPLUS >= 201703L
#  define CQ_NODISCARD [[nodiscard]]
#else
#  define CQ_NODISCARD
#endif
