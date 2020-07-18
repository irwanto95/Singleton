#include "pch.h"
#include "Inputs/InputKey.h"

namespace mufise
{
	namespace utils
	{
		InputKey::InputKey(sbit key, si16 state)
			: m_key(key)
			, m_state(state)
		{
		}

		InputKey::~InputKey()
		{
		}

		const si16& InputKey::GetValue() const
		{
			return m_key;
		}
	}
}