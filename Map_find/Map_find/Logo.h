#pragma once
#include "Scene.h"

class Logo : public Scene
{
public:
	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:

	Logo();
	virtual ~Logo();
};

