#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Release();
}

void Logo::Start()
{
	Time = GetTickCount64();
}

void Logo::Update()
{
	if (GetAsyncKeyState('A'))
	{
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
	}
}

void Logo::Render()
{
	//cout << "Logo" << endl;
}

void Logo::Release()
{
}
