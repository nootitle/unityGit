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
	
	//*** 출력 답안 ***
	//깊은 복사 버전
	auto temp = Objects["Enemy"];
	while (!temp.empty())
	{
		cout << temp.front()->iNumber << endl;
		temp.pop_front();
	}

	//iterator 버전
	for (auto itr = Objects["Enemy"].begin(); itr != Objects["Enemy"].end(); ++itr)
	{
		auto temp2 = *itr;
		cout << temp2->iNumber << endl;
	}
	
	return 0;
}