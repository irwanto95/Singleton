/*
	pch.h
*/
#include "mfpch.h"

#include "mufise/mfMath/Type/Vector.h"
#include "mufise/mfUtils/Core/Memory.h"
#include "mufise/mfUtils/IO/InputManager.h"
#include "mufise/mfUtils/File/File.h"

#include "mufise/mfUtils/Utils.h"

#include "../../example/_src/ObserverExample.h"
#include "../../example/_src/SingletonExample.h"

using namespace mufise;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<int> vint;
	DECL_IT_END(vector<int>, vint, ivint);

	/*
		mfUtils
	*/
	MFCUtils::ToLPCTSTR("Sultan");
	MFCUtils::ToLPCTSTR(string("korwak"));

	InputManager::CreateInstance();

	DECL_SHARED(Calculator, cal)();

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

	FILE* pFile;
	char buffer[] = { 'x' , 'y' , 'z' };
	pFile = fopen("myfile.bin", "w");
	fwrite(buffer, sizeof(char), sizeof(buffer), pFile);
	fclose(pFile);

	mufise::File file;
	file.Open("mfFile2.bin", mufise::File::EMode::Mode_WriteBin);
	file.Write(buffer, sizeof(buffer));
	file.Close();

	_CrtDumpMemoryLeaks();
	return EXIT_SUCCESS;
}