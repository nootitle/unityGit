#include <iostream>

using namespace std;

// ** �迭�� ���� : ���������� �����ϴ�. ���� �ӵ��� �׻� �����ϴ�.
// ** �迭�� ���� : ũ�⸦ ������ �� ����.(���� �ÿ� ��������� �޸� �Ҵ��� �ϱ� ����. ���ϱ� ����) ������ ����/���� ��, ������ ��迭�� �ʿ�
// ���� -> �ڵ� ����, ���� ����, static ������ �ε�, ����, ������ ���� -> ��Ÿ�� ���� -> �� ���
//(���ʹ� ����, �����Ϳ��� �ܿ��� ���� ����ϱ� ������, vector�� ũ�⸦ ������ �� �־���.)

int* CreateArray(int* _array, int length)
{
	int* temp = new int[length + 1];
	for (int i = 0; i < 10; ++i)
	{
		temp[i] = _array[i];
	}
	temp[10] = 11;
	free(_array);
	_array = nullptr;
	return temp;
}

int* ArrayPopBack(int* _array, int length)
{
	int* temp = new int[length - 1];
	for (int i = 0; i < length - 1; ++i)
		temp[i] = _array[i];
	free(_array);
	_array = nullptr;
	return temp;
}


int* ArrayErase(int* _array, int length, int index)
{
	int* temp = new int[length - 1];
	int index2 = 0;
	for (int i = 0; i < length - 1; ++i)
	{
		if(index2 != index) temp[i] = _array[index2++];
		else
		{
			--i;
			++index2;
		}		
	}
	/*
	string ����� memcpy(Array, _array, sizeof(int) * _length)�� 9�� ���� ���� ��, index ���ʸ� for������ �ٽ� �������� �� */

	free(_array);
	_array = nullptr;
	return temp;
}

int main()
{
	//int Array[10]; // ������ ũ��� ����θ� ��� -> ������ ������ ũ�Ⱑ �ö� -> ���ÿ� �ö� ����	
	int* Array = (int*)malloc(sizeof(int) * 10); // ���� �Ҵ�(�� ���)�� �̿��Ͽ�, ũ�� ����
	for (int i = 0; i < 10; ++i)
		Array[i] = i + 1;
	for (int i = 0; i < 10; ++i)
		cout << Array[i] << ' ';
	cout << '\n';
	Array = CreateArray(Array, 10);
	for (int i = 0; i < 11; ++i)
		cout << Array[i] << ' ';
	cout << '\n';
	//1. pop_back
	Array = ArrayPopBack(Array, 11);
	//Array[10] = NULL;
	for (int i = 0; i < 10; ++i)
		cout << Array[i] << ' ';
	cout << '\n';
	//2. 5 ������ ����
	Array = ArrayErase(Array, 10, 4);
	for (int i = 0; i < 9; ++i)
		cout << Array[i] << ' ';
	cout << '\n';

	return 0;
}