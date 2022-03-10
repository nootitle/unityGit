#pragma once
#include "headers.h"

class Scene;
class SceneManager
{
private:
	static SceneManager* Instance;
public:
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;
		return Instance;
	}
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

