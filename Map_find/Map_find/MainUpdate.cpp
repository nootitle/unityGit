#include "MainUpdate.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "headers.h"

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
	GETSINGLE(SceneManager)->SetScene(SCENEID_LOGO);
}

void MainUpdate::Update()
{
	GETSINGLE(SceneManager)->Update();
	
}

void MainUpdate::Render()
{
	GETSINGLE(SceneManager)->Render();

}

void MainUpdate::Release()
{
	DESTROY_SINGLETON(SceneManager);
}