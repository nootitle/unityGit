#include <iostream>
#include <list>

using namespace std;

typedef struct tagNode
{
	int value;
	tagNode* next;
}Node;

Node* back(Node* _pNode)
{
	if (_pNode->next != nullptr)
		back(_pNode->next);
	else
		return _pNode;
}

Node* pList = new Node;

void push_back(int _number, Node* _obj = pList)
{
	Node* pList2 = new Node;
	pList2->value = _number;
	pList2->next = nullptr;

	Node* backNode = back(pList);
	backNode->next = pList2;
}

int main()
{
	/*/
	int iArray[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* iIter = nullptr;
	iIter = iArray;	

	for (int i = 0; i < 10; i++)
	{
		if(iIter != nullptr)
			cout << *iIter << '\n';
		else break;
		iIter++;
	}

	list<int> numList = { 0, 1, 2, 3 ,4 };
	for (list<int>::iterator iter = numList.begin(); iter != numList.end(); iter++)
	{
		cout << *iter << endl;
	}
	*/
	pList->value = 0;
	pList->next = nullptr;

	for (int i = 0; i < 10; ++i)
	{
		push_back(i + 1, pList);
	}

	cout << back(pList)->value << endl;
	

	/*
	int i = 10;
	int j = 20;
	j ^= i;
	i ^= j;
	j ^= i;

	cout << "i : " << i << endl;
	cout << "j : " << j << endl;
	*/

	system("pause");
	return 0;
}

//배열크기 등은 2^n으로 : 컴파일러는 2^n가 아닌 수를 2^n인 수들의 연산으로 표현하므로, 메모리를 불필요하게 잡아먹게 된다.
//1 , !