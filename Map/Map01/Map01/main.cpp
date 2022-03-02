#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

/*
맵 특징
-> binary Tree 구조, 대소비교를 통한 자동정렬
-> 이후 특정 Key값을 찾을 때, 최상위부터 시작하여, 여러번의 대소비교를 통해 찾아감
-> 데이터를 모두 검사할 필요가 없으므로, 순회에 걸리는 시간이 매우 짧다.
-> 다만, 자동정렬 때문에, 데이터 삽입이 잦은 경우에는 비효율적이다.
*/

class Object
{
public:
	string Name;
	virtual int GetNumber() = 0;
	Object() {}
	Object(string _name) : Name(_name){} //초기화 형태를 잡아줌(string 값으로 초기화)
	Object(string _name, int i) { Name =  "Enemy" + to_string(i); } //초기화 형태를 잡아줌(string 값으로 초기화)
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
	Enemy(string _name) : Object(_name) {} //구체적인 초기화 모델 확립
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
	//*** 출력 답안 ***
	//답안1
	/*
	auto temp = Objects["Enemy"];
	while (!temp.empty())
	{
		cout << temp.front()->iNumber << endl;
		temp.pop_front();
	}
	*/
	//답안2
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