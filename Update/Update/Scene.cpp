#include "Scene.h"
#include "PlayerController.h"

void Scene::Init()
{
	Player = new PlayerController;
	Player->Init();
}

void Scene::Update()
{
	Player->Update();
}

void Scene::LateUpdate()
{
	Player->LateUpdate();
}

void Scene::render()
{
	Player->render();
}

void Scene::Destroy()
{
	Player->Destroy();
}

Scene::Scene()
{

}

Scene::~Scene()
{

}
