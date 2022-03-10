#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:

	Menu();
	virtual ~Menu();
};

