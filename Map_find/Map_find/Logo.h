#pragma once
#include "Object.h"

class Logo : public Object
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

	Logo();
	virtual ~Logo();
};

