#include "mfUtils/pch.h"
#include "Utils.h"

namespace mufise
{
	namespace utils
	{
		LPCTSTR MFCUtils::ToLPCTSTR(const std::string& str)
		{
			return ToLPCTSTR(str.c_str());
		}

		LPCTSTR MFCUtils::ToLPCTSTR(const char* str)
		{
#ifdef UNICODE
			const size_t sz = strlen(str) + 1;
			wchar_t* wc = new wchar_t[sz];
			mbstowcs(wc, str, sz);

			return wc;
#else
			return LPCTSTR(str);
#endif // UNICODE		
		}
	}
}