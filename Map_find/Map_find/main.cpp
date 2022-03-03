#include "MainUpdate.h"

//참고 : 클래스 내부에 정의된 함수는 inline 함수가 된다.
//inline : 컴파일러가 할 수 있는 한, 일반함수들보다 빨리 실행시키는 함수들
//일반 함수 : 코드영역(대기 큐) -> 실행(스택) / inline : 바로 실행(스택)
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