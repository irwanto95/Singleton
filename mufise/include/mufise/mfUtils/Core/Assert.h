#ifndef _MF_ASSERT_HPP
#define _MF_ASSERT_HPP

#include <assert.h>
#include "mufise/config.h"

#if MF_USE_ASSERT
#define MF_ASSERT(x)			assert(x)
#define MF_ASSERT_MSG(x, ...)	assert(x && __VA_ARGS__)
#else
#define MF_ASSERT(x)
#define MF_ASSERT_MSG(x, ...)
#endif // MF_USE_ASSERT

#endif // !_MF_ASSERT_HPP