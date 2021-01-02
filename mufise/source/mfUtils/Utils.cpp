#include "mfpch.h"
#include "mufise/mfUtils/Utils.h"

namespace mufise
{
	WCHAR MFCUtils::s_LPCTSTR_placeholder[];

	LPCTSTR MFCUtils::ToLPCTSTR(const std::string& str)
	{
		return ToLPCTSTR(str.c_str());
	}

	LPCTSTR MFCUtils::ToLPCTSTR(const char* str)
	{
		const size_t sz = strlen(str) + 1;
		MF_ASSERT(sz <= 2048);

		mbstowcs(s_LPCTSTR_placeholder, str, sz);

		return s_LPCTSTR_placeholder;
	}
} // mufise