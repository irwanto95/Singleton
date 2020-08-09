#ifndef _MF_MEMORY_H
#define _MF_MEMORY_H

#define _CRTDBG_MAP_ALLOC

#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define newleak new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define newleak new
#endif

#endif // !_MF_MEMORY_H
