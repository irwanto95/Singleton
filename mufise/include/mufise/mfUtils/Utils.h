#ifndef MFU_UTILS_H
#define MFU_UTILS_H

#include "windows.h"

namespace mufise
{
	class MFCUtils
	{
	private:
		static WCHAR s_LPCTSTR_placeholder[2048];
	
	public:
		static LPCTSTR ToLPCTSTR(const std::string& str);
		static LPCTSTR ToLPCTSTR(const char* str);
	};
} // mufise


#endif // !MFU_UTILS_H
