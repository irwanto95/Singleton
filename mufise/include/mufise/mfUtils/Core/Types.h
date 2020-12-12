#ifndef _MF_TYPES_H
#define _MF_TYPES_H

#include <stdint.h>

namespace mufise
{
	/*
		Integers
	*/
	typedef int8_t		si8;
	typedef int16_t		si16;
	typedef int32_t		si32;
	typedef int64_t		si64;

	typedef uint8_t		ui8;
	typedef uint16_t	ui16;
	typedef uint32_t	ui32;
	typedef uint64_t	ui64;

	typedef size_t		usize;

	typedef float		sf4;
	typedef double		sf8;

	/*
		Bits
	*/
	typedef int8_t		sbit8;
	typedef int16_t		sbit16;
	typedef int32_t		sbit32;
	typedef int64_t		sbit64;

	typedef uint8_t		ubit8;
	typedef uint16_t	ubit16;
	typedef uint32_t	ubit32;
	typedef uint64_t	ubit64;

#ifdef _WIN64
	typedef sbit64		sbit;
	typedef ubit64		ubit;
#else
	typedef sbit32		sbit;
	typedef ubit32		ubit;
#endif // _WIN64

	/*
		Macros
	*/
#define LISTV(x)	typedef std::vector<x>
#define LISTL(x)	typedef std::list<x>
#define LISTD(x)	typedef std::deque<x>
} // mufise

#endif // !_MF_TYPES_H
