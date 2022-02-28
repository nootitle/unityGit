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

};

class Enemy : public Object
{
public:
	int iNumber;
	Enemy() {}
	Enemy(int _i) : iNumber(_i) {}
};

int main()
{
	map<string, list<Enemy*>> Objects;
	list<Enemy*> Enemys;

	Enemys.push_back(new Enemy(1));
	Enemys.push_back(new Enemy(2));
	Enemys.push_back(new Enemy(3));
	Objects["Enemy"] = Enemys;
	
	//*** ��� ��� ***
	//���� ���� ����
	auto temp = Objects["Enemy"];
	while (!temp.empty())
	{
		cout << temp.front()->iNumber << endl;
		temp.pop_front();
	}

	//iterator ����
	for (auto itr = Objects["Enemy"].begin(); itr != Objects["Enemy"].end(); ++itr)
	{
		auto temp2 = *itr;
		cout << temp2->iNumber << endl;
	}
	
	return 0;
}