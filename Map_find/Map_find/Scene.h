#pragma once
#include "headers.h"

class Scene
{
protected:
	ULONGLONG Time;

public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};

