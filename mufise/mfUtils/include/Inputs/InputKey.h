#ifndef _MF_INPUT_KEY_H
#define _MF_INPUT_KEY_H

#include "Input.h"

namespace mufise
{
	namespace utils
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
			
			const bool		HasConsumed() { return m_bConsumed; }
			const si16		GetState() { return m_state; }
			const si16&		GetValue() const;

		private:
			bool m_bConsumed;
			si16 m_state;
			sbit m_key;
		};
	}
}

#endif // !_MF_INPUT_KEY_H
