#ifndef MF_UTILS_H
#define MF_UTILS_H

#include "windows.h"

namespace mufise
{
	class MFCUtils
	{
	public:
		static LPCTSTR ToLPCTSTR(const std::string& str);
		static LPCTSTR ToLPCTSTR(const char* str);
	};
} // mufise


#endif // !MF_UTILS_H
