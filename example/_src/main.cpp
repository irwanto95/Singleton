#include <stdlib.h>
#include <vector>

/*
	pch.h
*/
#include "mfMath/Math/vector.hpp"
#include "mfUtils/Core/assert.hpp"
#include "mfUtils/Core/declaration.hpp"
#include "mfUtils/Core/memory.hpp"
#include "mfUtils/Core/types.h"
#include "mfUtils/Inputs/InputManager.h"

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

	MAKE_SHARED(Calculator, cal)();

	InputManager::GetInstance()->AttachObserver(cal);
	InputManager::GetInstance()->Capture(InputKey(0x01, InputKey::KEY_PRESSED));
	InputManager::GetInstance()->Capture(InputKey(0x02, InputKey::KEY_PRESSED));
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

	std::vector<int> g;
	g.resize(10);
	g[0] = 1;
	g[1] = 34;
	g[2] = 10;
	g.resize(3);
	g.clear();

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}