#ifndef MFU_INPUT_KEY_H
#define MFU_INPUT_KEY_H

#include "Input.h"

namespace mufise
{
	class InputKey : public Input
	{
	public:
		enum EKeyEState
		{
			KEY_NONE = -1,
			KEY_PRESSED,
			KEY_RELEASED
		};

		InputKey(sbit key, si16 state = KEY_NONE);
		~InputKey();

		virtual si16	GetType() const { return KEY; };
			
		const si16		GetState() const { return m_state; }
		const si16&		GetValue() const;

	private:
		si16 m_state;
		sbit m_key;
	};
} // mufise

#endif // !MFU_INPUT_KEY_H
