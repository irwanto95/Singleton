#include <stdlib.h>

#include "Math/vector.hpp"
#include "Singleton/Singleton.h"

using namespace mufise;

class Object0 : public utils::Singleton<Object0>
{
public:
	Object0()
		: m(0)
	{
	};
	
private:
	int m;
};

class Object1 : public utils::Singleton<Object1>
{
public:
	Object1(int _m)
		: m(_m)
	{
	};

private:
	int m;
};

class Object2 : public utils::Singleton<Object2>
{
public:
	Object2(int _m, char _c)
		: m(_m)
		, c(_c)
	{
	};

private:
	int m;
	char c;
};

int main()
{
	Object0::CreateInstance();
	Object1::CreateInstance(5);
	Object2::CreateInstance(6, 'g');

	math::vector<int> v2i(2,3);
	math::vector<int> v2h(v2i);
	math::vecf v3f;

	Object0::DeleteInstance();
	Object1::DeleteInstance();
	Object2::DeleteInstance();

	system("pause");
	return EXIT_SUCCESS;
}