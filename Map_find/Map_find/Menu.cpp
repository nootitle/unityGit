#include "Menu.h"
#include "SceneManager.h"

void Menu::Start()
{
	Time = GetTickCount64();
}

void Menu::Update()
{
	if (GetAsyncKeyState('S'))
	{
		SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
	}
}

void Menu::Render()
{
	//cout << "Menu" << endl;
}

void Menu::Release()
{
}

Menu::Menu()
{
}

Menu::~Menu()
{
}
