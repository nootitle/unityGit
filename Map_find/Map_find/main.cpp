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

//오버로딩 vs 오버라이딩
//오버로딩 : 같은 클래스 내에서의 함수 재정의(매개변수를 다르게 주는 방식)
//오버라이딩 : 상속 관계에서의 함수 재정의(자식클래스에서 상속받은 함수를 재정의하는 방식)
//참고 : 포인터선언을 부모클래스 형태의 포인터로 하면, 오버로딩이 적용되지 않고, 부모함수가 호출된다.
//new 클래스명 == 클래스만큼의 size의 공간을 heap에 할당(자식클래스의 기능을 받지는 않음)
//단! virtual 함수의 경우, new 뒤의 클래스의 함수를 호출한다. 때문에
//함수를 virtual로 선언해두면, 오버로딩이 씹히는 경우가 없다.(부모, 포인터 데이터타입따윈 무시하고 new 뒤 클래스의 함수사용)

//상속관계에서의 생성자, 소멸자 : 부모 생성자 -> 자식 생성자 -> 자식 소멸자 -> 부모 소멸자 순으로 호출
//delete에서 이점을 유의해야 함(delete는 기본적으로 상속관계를 고려하지 않기에, 소멸자에 virtual을 써야 부모, 자식 소멸자를 모두 호출한다.)

/*
class Singleton
{
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr) Instance = new Singleton;
		return Instance;
	}
private: //싱글톤은 임의로 인스턴스를 생성하지 못하게 막아야 함
	Singleton() {}
	~Singleton() {}
};

class AAA
{
public:
	virtual void out() { cout << "o" << endl; }
	AAA() { cout << "aa" << endl; }
	virtual ~AAA() { cout << "ab" << endl; }
};

class BBB : public AAA
{
public:
	virtual void out() { cout << "ow" << endl; }
	BBB() { cout << "ba" << endl; }
	virtual ~BBB() { cout << "bb" << endl; }
};
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
	
	//Singleton* a = new Singleton();
	//delete a;
	
	//AAA* a = new AAA;
	/*
	AAA* b = new BBB; // == AAA* aa = (BBB*)malloc(sizeof(BBB)); & BBB 생성자도 호출 상태
	b->out();
	delete b;
	*/

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		system("cls");
		Main.Update();
		Main.Render();
	}

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