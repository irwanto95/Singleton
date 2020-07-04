#include <stdlib.h>
#include "Object.h"

int main()
{
	Object::CreateInstance("argument");

	// do your code

	Object::DeleteInstance();

	system("pause");
	return EXIT_SUCCESS;
}