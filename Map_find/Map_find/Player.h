#pragma once
#include "Object.h"

class Player : public Object
{
public:
	virtual void Start();
	virtual void Update();
	virtual void Render();
	virtual void Release();
public:

	Player();
	virtual ~Player();
};

