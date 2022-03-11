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
	if (itr == Objects.end()) //Key�� ���� ���
	{
		list<Object*> ObjectList;
		ObjectList.push_back(_Obj);
		Objects.insert(make_pair(_Obj->GetKey(), ObjectList));
	}
	else //Key�� �ִ� ���
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

void ObjectManager::Release()
{
	for (auto itr = Objects.begin(); itr != Objects.end(); ++itr)
		for (auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
			::Safe_Delete(*itr2);
}

list<Object*>* ObjectManager::FindList(string _strkey)
{
	auto itr = Objects.find(_strkey);

	if (itr == Objects.end())
		return nullptr;
	else
		return &itr->second;
}
