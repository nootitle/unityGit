#include <iostream>
#include <list>

using namespace std;

class Node
{
public:
	int value;
	Node* back;
};

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
	
	Node* pList = new Node;

	pList->value = 1;
	pList->back = nullptr;

	Node* pNode = new Node;

	pNode->value = 1;
	pNode->back = nullptr;

	pList->back = pNode;

	cout << pList->value << endl;
	cout << pList->back->value << endl;
	
	return 0;
}