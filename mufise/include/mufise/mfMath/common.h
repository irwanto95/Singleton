#ifndef MFM_COMMON_H
#define MFM_COMMON_H

#include <algorithm>

namespace mufise
{
	/*	@url: http://realtimecollisiondetection.net/pubs/Tolerances/
		@desc:	abs(x - y) <= max(absolute_tolerance, realtive_tolerance * max(abs(x), abs(y)))
				assume absolute_tolerance = realtive_tolerance, leaves
				abs(x - y) <= absolute_tolerance * max(1.0f, abs(x), abs(y))
	*/
	inline bool equals(float s0, float s1, float tolerance = FLT_EPSILON)
	{
		assert(tolerance >= 0);
		return std::abs(s0 - s1) <= tolerance * std::max(1.0f, std::max(abs(s0), abs(s1)));
	}

	inline bool equals(double s0, double s1, double tolerance = DBL_EPSILON)
	{
		assert(tolerance >= 0);
		return std::abs(s0 - s1) <= tolerance * std::max(1.0, std::max(abs(s0), abs(s1)));
	}

	template<typename _Type>
	inline bool equals(_Type s0, _Type s1)
	{
		return s0 == s1;
	}
} // mufise

#endif // MFM_COMMON_H
