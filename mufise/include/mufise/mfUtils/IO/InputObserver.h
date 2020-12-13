#ifndef MFU_INPUT_OBSERVER_H
#define MFU_INPUT_OBSERVER_H

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

#endif // !MFU_INPUT_OBSERVER_H
