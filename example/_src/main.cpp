#include <stdlib.h>
#include <vector>

/*
	pch.h
*/
#include "Math/vector.hpp"
#include "Core/assert.hpp"
#include "Core/declaration.hpp"
#include "Core/memory.hpp"
#include "Core/types.h"
#include "Inputs/InputManager.h"

#include "../../example/_src/ObserverExample.h"
#include "../../example/_src/SingletonExample.h"

using namespace mufise::math;
using namespace mufise::utils;
//
//class Object0 : public utils::Singleton<Object0>
//{
//public:
//	Object0()
//		: m(0)
//	{
//	};
//	
//private:
//	int m;
//};
//
//class Object1 : public utils::Singleton<Object1>
//{
//public:
//	Object1(int _m)
//		: m(_m)
//	{
//	};
//
//private:
//	int m;
//};
//
//class Object2 : public utils::Singleton<Object2>
//{
//public:
//	Object2(int _m, char _c)
//		: m(_m)
//		, c(_c)
//	{
//	};
//
//private:
//	int m;
//	char c;
//};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	/*
		mfUtils
	*/
	InputManager::CreateInstance();

	DECL_SHARED(Calculator, cal)();

	InputManager::GetInstance()->AttachObserver(cal);
	InputManager::GetInstance()->Capture(InputKey(0x01));
	InputManager::GetInstance()->Capture(InputKey(0x02));
	InputManager::GetInstance()->Update();
	InputManager::DeleteInstance();

	/*
		mfMath
	*/
	vector2<int> v2i(2,3);
	vector2<int> v2h(v2i);
	vec2f v3f;
	vec2f v3f2(0.3f, 0.1f);

	v3f = v3f2 * 2;
	v3f = v3f2 * 0;
	v3f = v3f2 / 1;
	//v3f = v3f2 / 0;

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}