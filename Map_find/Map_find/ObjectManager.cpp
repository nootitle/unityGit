#include "ObjectManager.h"
#include "Object.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(Object * _Obj)
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

Object * ObjectManager::FindPlayer()
{
	map<string, list<Object*>>::iterator itr = Objects.find("Player");

	if (itr == Objects.end())
		return nullptr;
	else
	{
		cout << "FP" << endl;
		return itr->second.front();
	}

}

void ObjectManager::setActive(string kind, int index, bool value)
{
	map<string, list<Object*>>::iterator itr = Objects.find(kind);
	auto itr2 = itr->second.begin();
	for (int i = 0; i < index; ++i)
		itr2++;
	(*itr2)->SetActive(value);

}

list<Object*>* ObjectManager::FindList(string _strkey)
{
	auto itr = Objects.find(_strkey);

	if (itr == Objects.end())
		return nullptr;
	else
		return &itr->second;
}
