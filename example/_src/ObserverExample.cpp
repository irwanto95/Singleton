#include "mfupch.h"
#include "ObserverExample.h"

using namespace mufise::utils;

Calculator::Calculator()
{
	cout << "Calculator" << endl;
}

Calculator::~Calculator()
{
	cout << "~Calculator" << endl;
}

void Calculator::OnKeyPressed(const InputKey& input)
{
	// to do
}
