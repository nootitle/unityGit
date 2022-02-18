#include "mainUpdate.h"
#include "headers.h"
#include "Scene.h"

void mainUpdate::Init()
{
	_scene = new Scene;
	_scene->Init();
}

void mainUpdate::Update()
{
	_scene->Update();
}

void mainUpdate::LateUpdate()
{
	_scene->LateUpdate();
}

void mainUpdate::FixedUpdate()
{
	cout << "FixedUpdate" << endl;
}

void mainUpdate::render()
{
	_scene->render();
}

void mainUpdate::Destroy()
{
	_scene->Destroy();
}

mainUpdate::mainUpdate()
{

}

mainUpdate::~mainUpdate()
{
}
