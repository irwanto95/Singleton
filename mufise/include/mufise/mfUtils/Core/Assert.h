#ifndef MFU_ASSERT_H
#define MFU_ASSERT_H

#include <assert.h>
#include "mufise/config.h"

#if MF_USE_ASSERT
#define MF_ASSERT(x)			assert(x)
#define MF_ASSERT_MSG(x, ...)	assert(x && __VA_ARGS__)
#else
#define MF_ASSERT(x)
#define MF_ASSERT_MSG(x, ...)
#endif // MF_USE_ASSERT

#endif // !MFU_ASSERT_H