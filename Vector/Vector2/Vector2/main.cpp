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
	[void ������]
	���� �����ϰ�, �ּ�(4byte(64bit ä�� : 8byte))�� ����
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
	memcpy(Temp, InfoList, sizeof(INFO) * capacity); //������ �����͸� ����Ű�� �����͸� �ϳ� �� ����
												   //�ֳĸ� �Ű������� �����ʹϱ�.
	if (capacity < 3)
	{
		++capacity;
		InfoList = new INFO[capacity];
		for (int i = 0; i < capacity - 1; ++i)
			InfoList[i] = Temp[i];
		InfoList[Size].Value = _value;
	}
	else //capacity >> 1��ŭ �߰�(���� �߰��� ���� ����� �̸� ������ �߰��Ҵ�)
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
