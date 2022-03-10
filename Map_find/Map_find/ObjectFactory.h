#pragma once
#include "Object.h"

class ObjectFactory
{
public:
	template <typename T>
	static Object* CreateObject(int _num)
	{
		Object* pObj = new T;
		pObj->Start();
		pObj->SetNumber(_num);
		return pObj;
	}

	template <typename T>
	static Object* CreateObject(float _x, float _y)
	{
		Object* pObj = new T;
		//pObj->Initialize();
		pObj->Start();
		pObj->SetPosition(_x, _y);
		return pObj;
	}
	
	template <typename T>
	static Object* CreateObject(Vector3 _pos)
	{
		Object* pObj = new T;
		//pObj->Initialize();
		pObj->Start();
		pObj->SetPosition(_pos);
		return pObj;
	}

	template <typename T>
	static Object* CreateObject(Vector3 _pos, Vector3 _rot)
	{
		Object* pObj = new T;
		//pObj->Initialize();
		pObj->Start();
		pObj->SetPosition(_pos);
		pObj->SetRotation(_rot);
		return pObj;
	}
};

/*
void Enemy::Initialize()
{
	strKey = "Enemy";
}

template <typename T>
Object* CreateObject()
{
	Object* pObj = new T;
	pObj->Initialize();
	return pObj;
}
template <typename T>
Object* CreateObject(int _num)
{
	Object* pObj = new T;
	pObj->Initialize();
	pObj->SetNumber(_num);
	return pObj;
}
template <typename T>
void AddObject()
{
	Object* pObj = CreateObject<T>();
}
template <typename T>
void AddObject(int _num)
{
	Object* pObj = CreateObject<T>(_num);
}

void AddObject(Object* _Obj)
{
	auto itr = Objects.find(_Obj->GetKey());
	if (itr == Objects.end()) //Key가 없는 경우
	{
		list<Object*> ObjectList;
		ObjectList.push_back(_Obj);
		Objects.insert(make_pair(_Obj->GetKey(), ObjectList));
	}
	else //Key가 있는 경우
	{
		itr->second.push_back(_Obj);
	}
}
*/