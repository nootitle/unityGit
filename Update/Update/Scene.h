#pragma once
#include "mainUpdate.h"

class PlayerController;
class Scene : mainUpdate
{
private:
	PlayerController* Player;
public:
	void Init();
	void Update();
	void LateUpdate();
	void render();
	void Destroy();
public:
	Scene();
	~Scene();
};

