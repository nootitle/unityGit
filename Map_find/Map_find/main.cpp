#include "MainUpdate.h"

//���� : Ŭ���� ���ο� ���ǵ� �Լ��� inline �Լ��� �ȴ�.
//inline : �����Ϸ��� �� �� �ִ� ��, �Ϲ��Լ��麸�� ���� �����Ű�� �Լ���
//�Ϲ� �Լ� : �ڵ念��(��� ť) -> ����(����) / inline : �ٷ� ����(����)
/*
class Object
{
protected:
	string strKey;
	int iNumber;
public:
	virtual void Initialize() = 0;
public:
	void SetNumber(int _num) { iNumber = _num; }
	int GetNumber() { return iNumber; }
	string GetKey() { return strKey; }
};

class Enemy : public Object
{
public:
	virtual void Initialize() override;
	int GetNumber() { return iNumber; }
};

template <typename T>
Object* CreateObject();
template <typename T>
Object* CreateObject(int _num);
template <typename T>
void AddObject();
template <typename T>
void AddObject(int _num);
map<string, list<Object*>> Objects;

void AddObject(Object* _Obj);
*/
int main()
{	
	/*
	for (int i = 0; i < 10; ++i)
	{
		Object* pObj = CreateObject<Enemy>(i);
		AddObject(pObj);
	}
	for (auto itr = Objects.begin(); itr != Objects.end(); ++itr)
		for (auto itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
			cout << (*itr2)->GetNumber() << endl;


*/	
	


	return 0;
}
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
*/