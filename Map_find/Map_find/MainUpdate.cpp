#include "MainUpdate.h"
#include "SceneManager.h"
#include "CursorManager.h"

MainUpdate::MainUpdate()
{
	iNumber = 0;
}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(SCENEID_LOGO);
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();
	
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();

}

void MainUpdate::Release()
{
	
}