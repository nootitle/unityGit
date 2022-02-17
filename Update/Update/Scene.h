#pragma once
#include "mainUpdate.h"

class PlayerController;
class Scene : mainUpdate
{
private:
	PlayerController* Player;
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void render() = 0;
	virtual void Destroy() = 0;
public:
	Scene();
	~Scene();
};

