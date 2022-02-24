#include <iostream>

using namespace std;

// ** 배열의 장점 : 직접접근이 가능하다. 접근 속도가 항상 일정하다.
// ** 배열의 단점 : 크기를 조절할 수 없다.(선언 시에 상수값으로 메모리 할당을 하기 때문. 정하기 때문) 데이터 삽입/삭제 시, 원소의 재배열이 필요
// 실행 -> 코드 영역, 전역 변수, static 변수만 로드, 스택, 데이터 세팅 -> 런타임 시작 -> 힙 사용
//(벡터는 스택, 데이터영역 외에도 힙도 사용하기 때문에, vector는 크기를 조절할 수 있었다.)

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
	string 헤더의 memcpy(Array, _array, sizeof(int) * _length)로 9개 원소 복사 후, index 뒤쪽만 for문으로 다시 덫씌워도 됨 */

	free(_array);
	_array = nullptr;
	return temp;
}

int main()
{
	//int Array[10]; // 데이터 크기는 상수로만 사용 -> 데이터 영역에 크기가 올라감 -> 스택에 올라가 생성	
	int* Array = (int*)malloc(sizeof(int) * 10); // 동적 할당(힙 사용)을 이용하여, 크기 조절
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
	//2. 5 데이터 삭제
	Array = ArrayErase(Array, 10, 4);
	for (int i = 0; i < 9; ++i)
		cout << Array[i] << ' ';
	cout << '\n';

	return 0;
}