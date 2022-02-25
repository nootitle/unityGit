#include <iostream>
#include <string>
using namespace std;

typedef struct tagInfo
{
	int Value;

}INFO;

int capacity = 0;
int Size = 0;
INFO* InfoList;

void push_back(int _value);
void erase(int _index);
//INFO* ierase(void* _Where);

/*
	[void 포인터]
	값과 무관하게, 주소(4byte(64bit 채제 : 8byte))만 받음
*/

int main()
{
	InfoList = new INFO[capacity];
	push_back(10);
	push_back(20);
	push_back(30);
	push_back(40);
	push_back(50);
	push_back(60);
	push_back(70);
	erase(2);
	for (int i = 0; i < Size; ++i)
		cout << InfoList[i].Value << endl;
	
	//for(int i = 0; i < 3; ++i)
		//if(i == 3)
			//erase(&InfoList[i]);

	system("pause");
	return 0;
}

void push_back(int _value)
{
	INFO* Temp = new INFO[capacity];
	memcpy(Temp, InfoList, sizeof(INFO) * capacity); //동일한 데이터를 가리키는 포인터를 하나 더 선언
												   //왜냐면 매개변수가 포인터니까.
	if (capacity < 3)
	{
		++capacity;
		InfoList = new INFO[capacity];
		for (int i = 0; i < capacity - 1; ++i)
			InfoList[i] = Temp[i];
		InfoList[Size].Value = _value;
	}
	else //capacity >> 1만큼 추가(추후 추가될 값에 대비해 미리 공간을 추가할당)
	{
		if (capacity <= Size)
		{
			capacity += capacity >> 1;
			InfoList = new INFO[capacity];
		}

		for (int i = 0; i < capacity - 1; ++i)
			InfoList[i] = Temp[i];
		InfoList[Size].Value = _value;
	}
	++Size;
}

void erase(int _index)
{
	INFO* Temp = new INFO[capacity];
	memcpy(Temp, InfoList, sizeof(INFO) * capacity);
	--capacity;
	InfoList = new INFO[capacity];
	for (int i = 0; i < _index; ++i)
		InfoList[i] = Temp[i];
	for (int i = _index + 1; i < capacity; ++i)
		InfoList[i - 1] = Temp[i];
	--Size;
}

//INFO * ierase(void* _Where)
//{
	//INFO* itr = 
	//return nullptr;
//}
