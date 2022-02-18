#pragma once
#include "mainUpdate.h"
#include "Obejct.h"

class Object;
class PlayerController : public Obejct
{
public:
	virtual void Init();
	virtual void Update();
	virtual void LateUpdate();
	virtual void render();
	virtual void Destroy();
public:
	PlayerController();
	virtual ~PlayerController();
};

