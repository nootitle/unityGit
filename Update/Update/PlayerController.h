#pragma once
#include "mainUpdate.h"

class PlayerController : mainUpdate
{
public:
	void Init();
	void Update();
	void LateUpdate();
	void render();
	void Destroy();
public:
	PlayerController();
	~PlayerController();
};

