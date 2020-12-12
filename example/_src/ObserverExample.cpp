#include "mfpch.h"
#include "ObserverExample.h"

using namespace mufise;

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
