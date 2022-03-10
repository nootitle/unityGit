#pragma once
#include "headers.h"

class Object
{
protected:
	Transform Info;
	string strKey;
	int iNumber;
	bool isActive = true;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetNumber(int _num) { iNumber = _num; }
	int GetNumber() { return iNumber; }
	string GetKey() { return strKey; }
	void Initialize() { strKey = ""; }
	Vector3 GetPosition() const { return Info.Position; }
	void SetPosition(const Vector3& _Position) { Info.Position = _Position; }
	void SetPosition(const float& _x, const float& _y) { Info.Position.x = _x; Info.Position.y = _y; }
	Vector3 GetRotation() const { return Info.Rotaiton; }
	void SetRotation(const Vector3& _Rotation) { Info.Rotaiton = _Rotation; }
	void SetRotation(const float& _x, const float& _y) { Info.Rotaiton.x = _x; Info.Rotaiton.y = _y; }
	Vector3 GetScale() const { return Info.Scale; }
	void SetScale(const Vector3& _Scale) { Info.Scale = _Scale; }
	void SetScale(const float& _x, const float& _y) { Info.Scale.x = _x; Info.Scale.y = _y; }
	void SetActive(bool value) { isActive = value; }

	Object();
	Object(int num);
	virtual ~Object();
};