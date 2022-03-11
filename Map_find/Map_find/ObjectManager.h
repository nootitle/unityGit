#pragma once
#include "headers.h"
#include "ObjectFactory.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
	map<string, list<Object*>> Objects;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
public:
	void AddObject(Object* _Obj);
	list<Object*>* FindList(string _strkey);
	Object* FindPlayer();
	void setActive(string kind, int index, bool value);
	void Release();
private:
	ObjectManager();
public:
	~ObjectManager();
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