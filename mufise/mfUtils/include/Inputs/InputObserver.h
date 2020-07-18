#ifndef _MF_INPUT_OBSERVER_H
#define _MF_INPUT_OBSERVER_H

#include "Inputs/InputKey.h"

namespace mufise
{
	namespace utils
	{
		class InputObserver
		{
		protected:
			InputObserver() {};
			virtual ~InputObserver() {};

		public:
			virtual void OnKeyPressed(const InputKey& input) = 0;
		};	
	
		MAKE_SHARED(InputObserver);
	}
}

#endif // !_MF_INPUT_OBSERVER_H