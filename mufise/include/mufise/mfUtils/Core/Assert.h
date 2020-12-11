#ifndef _MF_ASSERT_HPP
#define _MF_ASSERT_HPP

#include <assert.h>

#define MF_ASSERT(x)			assert(x)
#define MF_ASSERT_MSG(x, ...)	assert(x && __VA_ARGS__)

#endif // !_MF_ASSERT_HPP