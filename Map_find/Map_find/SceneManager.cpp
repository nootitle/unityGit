#include "SceneManager.h"
#include "Logo.h"
#include "Stage.h"
#include "Menu.h"

SceneManager* SceneManager::Instance = nullptr; //static 변수는 전역 초기화를 함

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(SCENEID _ID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_ID)
	{
	case SCENEID_LOGO: 
		SceneState = new Logo;
		break;
	case SCENEID_MENU:
		SceneState = new Menu;
		break;
	case SCENEID_STAGE:
		SceneState = new Stage;
		break;
	case SCENEID_EXIT:
		exit(NULL);
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	SceneState->Release();
}
