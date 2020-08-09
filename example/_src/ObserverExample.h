#ifndef _MF_OBSERVER_EXAMPLE_H
#define _MF_OBSERVER_EXAMPLE_H

#include "mfUtils/Inputs/InputObserver.h"

class Calculator : public mufise::utils::InputObserver
{
public:
	Calculator();
	~Calculator();

	void OnKeyPressed(const mufise::utils::InputKey& input);
};

DECL_SHARED(Calculator);

#endif // !_MF_OBSERVER_EXAMPLE_H