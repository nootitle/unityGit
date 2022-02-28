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
void pop_back();
void erase(int _index);
INFO* ierase(const void* _Where);

int size();
int Capacity();

void output();

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
	pop_back();
	//erase(2);
	
	INFO* test = nullptr;
	for(int i = 0; i < Size; ++i)
		if(i == 3)
			test = ierase(&InfoList[i]);

	//cout << test->Value << endl << endl;
	output();

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

void pop_back()
{
	--Size;
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

INFO * ierase(const void* _Where)
{
	int Start = 0;
	for (int i = 0; i < Size; ++i)
	{
		if (InfoList[i].Value == ((INFO*)_Where)->Value)
		{
			Start = i;
			break;
		}
	}
	--Size;
	for (int i = Start; i < Size; ++i)
	{
		InfoList[i] = InfoList[i + 1];
	}

	return &InfoList[Start];
}

int size()
{
	return Size;
}

int Capacity()
{
	return capacity;
}

void output()
{
	for (int i = 0; i < Size; ++i)
		cout << InfoList[i].Value << endl;
}
