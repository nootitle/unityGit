#pragma once
#include "headers.h"

class Object
{
protected:
	string strKey;
	int iNumber;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetNumber(int _num) { iNumber = _num; }
	int GetNumber() { return iNumber; }
	string GetKey() { return strKey; }

	Object();
	virtual ~Object();
};