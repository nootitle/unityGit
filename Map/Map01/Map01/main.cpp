#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

/*
�� Ư¡
-> binary Tree ����, ��Һ񱳸� ���� �ڵ�����
-> ���� Ư�� Key���� ã�� ��, �ֻ������� �����Ͽ�, �������� ��Һ񱳸� ���� ã�ư�
-> �����͸� ��� �˻��� �ʿ䰡 �����Ƿ�, ��ȸ�� �ɸ��� �ð��� �ſ� ª��.
-> �ٸ�, �ڵ����� ������, ������ ������ ���� ��쿡�� ��ȿ�����̴�.
*/

class Object
{
public:
	string Name;
	virtual int GetNumber() = 0;
	Object() {}
	Object(string _name) : Name(_name){} //�ʱ�ȭ ���¸� �����(string ������ �ʱ�ȭ)
	Object(string _name, int i) { Name =  "Enemy" + to_string(i); } //�ʱ�ȭ ���¸� �����(string ������ �ʱ�ȭ)
	~Object() {}
};

class Enemy : public Object
{
public:
	int iNumber;
	virtual int GetNumber() override
	{
		return iNumber;
	}

public:
	Enemy() {}
	Enemy(string _name) : Object(_name) {} //��ü���� �ʱ�ȭ �� Ȯ��
	Enemy(string _name, int i) { Name = "Enemy" + to_string(i); }
	Enemy(int _i) : iNumber(_i) {}
};

int main()
{
	/*
	map<string, list<Enemy*>> Objects;
	list<Enemy*> Enemys;

	for(int i = 0; i < 100; ++i)
	Enemys.push_back(new Enemy(i));

	Objects["Enemy"] = Enemys;
	*/
	//*** ��� ��� ***
	//���1
	/*
	auto temp = Objects["Enemy"];
	while (!temp.empty())
	{
		cout << temp.front()->iNumber << endl;
		temp.pop_front();
	}
	*/
	//���2
	/*
	for (auto itr = Objects["Enemy"].begin(); itr != Objects["Enemy"].end(); ++itr)
	{
		auto temp2 = *itr;
		cout << temp2->iNumber << endl;
	}
	*/

	map<int, Object*> Objects;

	for (int i = 0; i < 100; ++i)
		Objects.insert(make_pair(i, new Enemy("Enemy", i)));

	for (auto itr = Objects.begin(); itr != Objects.end(); ++itr)
		cout << itr->second->Name << endl;

	auto itr = Objects.find(0);
	cout << itr->second->Name << endl;

	return 0;
}