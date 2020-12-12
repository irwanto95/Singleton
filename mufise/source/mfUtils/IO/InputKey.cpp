#include "mfpch.h"
#include "mufise/mfUtils/IO/InputKey.h"

namespace mufise
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
} // mufise