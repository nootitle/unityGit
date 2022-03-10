#pragma once
#include "headers.h"

class MainUpdate
{
private:
	int iNumber;
	ULONGLONG Time;
public:
	void Start();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};

