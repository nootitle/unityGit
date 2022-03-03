#pragma once
#include "Object.h"

class Enemy : public Object
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
	int GetNumber() { return iNumber; }

	Enemy();
	virtual ~Enemy();
};