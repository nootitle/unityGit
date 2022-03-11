#pragma once
#include "headers.h"

class Scene;
class SceneManager
{
public:
	DECLARE_SINGLETON(SceneManager);
private:
	Scene* SceneState;
public:
	void SetScene(SCENEID _ID);
	void Update();
	void Render();
	void Release();
private:
	SceneManager();
public:
	~SceneManager();
};

