#include <stdlib.h>
#include "Object.h"

int main()
{
	Object::CreateInstance("argument");
	Object1::CreateInstance();
	Object2::CreateInstance("argument", 0);

	// do your code

	Object::DeleteInstance();
	Object1::DeleteInstance();
	Object2::DeleteInstance();

	system("pause");
	return EXIT_SUCCESS;
}