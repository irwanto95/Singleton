#ifndef _MF_INPUT_OBSERVER_H
#define _MF_INPUT_OBSERVER_H

#include "InputKey.h"

namespace mufise
{
	class InputObserver
	{
	protected:
		InputObserver() {};
		virtual ~InputObserver() {};

	public:
		virtual void OnKeyPressed(const InputKey& input) = 0;
	};	
	
	MAKE_SMART_PTR(InputObserver);
} // mufise

#endif // !_MF_INPUT_OBSERVER_H
