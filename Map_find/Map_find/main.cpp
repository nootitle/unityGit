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

//�����ε� vs �������̵�
//�����ε� : ���� Ŭ���� �������� �Լ� ������(�Ű������� �ٸ��� �ִ� ���)
//�������̵� : ��� ���迡���� �Լ� ������(�ڽ�Ŭ�������� ��ӹ��� �Լ��� �������ϴ� ���)
//���� : �����ͼ����� �θ�Ŭ���� ������ �����ͷ� �ϸ�, �����ε��� ������� �ʰ�, �θ��Լ��� ȣ��ȴ�.
//new Ŭ������ == Ŭ������ŭ�� size�� ������ heap�� �Ҵ�(�ڽ�Ŭ������ ����� ������ ����)
//��! virtual �Լ��� ���, new ���� Ŭ������ �Լ��� ȣ���Ѵ�. ������
//�Լ��� virtual�� �����صθ�, �����ε��� ������ ��찡 ����.(�θ�, ������ ������Ÿ�Ե��� �����ϰ� new �� Ŭ������ �Լ����)

//��Ӱ��迡���� ������, �Ҹ��� : �θ� ������ -> �ڽ� ������ -> �ڽ� �Ҹ��� -> �θ� �Ҹ��� ������ ȣ��
//delete���� ������ �����ؾ� ��(delete�� �⺻������ ��Ӱ��踦 ������� �ʱ⿡, �Ҹ��ڿ� virtual�� ��� �θ�, �ڽ� �Ҹ��ڸ� ��� ȣ���Ѵ�.)

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
private: //�̱����� ���Ƿ� �ν��Ͻ��� �������� ���ϰ� ���ƾ� ��
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

typedef struct Info
{
	int iNumber;

	Info() {};
	Info(int _Number) :iNumber(_Number) {}
}INFO;

class AAA
{
public:
	INFO* info;
public:
	template<typename T>
	AAA* Clone(int num)
	{
		return new T(new INFO(num));
	}
	template<typename T>
	AAA* Clone()
	{
		return new T(new INFO(info->iNumber));
	}

	AAA(Info* _Info) : info(_Info) {}
	AAA(AAA* _a) {}
	AAA() {}
	~AAA() {}
};

class BBB : public AAA
{
public:
	BBB(Info* _Info) : AAA(_Info) {}
	BBB(AAA* _a) {}
	BBB() {}
	~BBB() {}
};

class CCC : public AAA
{
public:
	CCC(Info* _Info) : AAA(_Info) {}
	CCC(AAA* _a) {}
	CCC() {}
	~CCC() {}
};

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
	AAA* b = new BBB; // == AAA* aa = (BBB*)malloc(sizeof(BBB)); & BBB �����ڵ� ȣ�� ����
	b->out();
	delete b;
	*/

	/*
	AAA* a1 = new BBB(new INFO(10));
	AAA* a2 = new CCC(new INFO(20));

	cout << a1->info->iNumber << endl;
	cout << a2->info->iNumber << endl;
	*/


	AAA* a3 = new AAA(new INFO(30)); //Prefab

	AAA* a4 = a3->Clone<BBB>(500); //�ν��Ͻ���
	AAA* a5 = a3->Clone<CCC>(600);
	AAA* a6 = a3->Clone<BBB>();

	cout << a3->info->iNumber << endl;

	cout << a4->info->iNumber << endl;
	cout << a5->info->iNumber << endl;
	cout << a6->info->iNumber << endl;

	/*
	MainUpdate Main;
	Main.Start();

	while (true)
	{
		system("cls");
		Main.Update();
		Main.Render();
	}
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