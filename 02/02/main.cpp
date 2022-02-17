#include <iostream>
#include <list>

using namespace std;

typedef struct tagNode
{
public:
	tagNode* front = nullptr;
	int value = 0;
	tagNode* back = nullptr;
}Node, *Node_iterator;

typedef struct tagIterator
{
	tagNode* front;
	tagNode* pThis;
	tagNode* back;
}iIterator;

void push_back(int value, Node* node);
Node* front(Node* node);
Node* back(Node* _pList);
void Delete(int _where, Node* _pList);
Node* erase(int _where, Node* _pList);
int size(Node* _pList, int _count);
iIterator begin(Node* _pList);
iIterator end(Node* _pList);

int size_backup;

int main()
{
	Node* pList = new Node;
	pList->value = 10;
	for(int i = 1; i < 9; i++)
		push_back((i + 1) * 10, pList);

	erase(2, pList);

	//cout << erase(1, pList)->value << endl;
	//cout << pList->back->value << endl;

	/*
	int i = 0;
	for (Node* itr = pList; itr != nullptr; itr = itr->back)
	{
		i++;
		//if(i == 2)
			//itr = erase(0, itr);
		cout << itr->value << endl;
	}
	*/

	for (iIterator itr = begin(pList); itr.pThis != end(pList).pThis; itr.pThis = itr.pThis->back)
	{
		cout << itr.pThis->value << endl;
	}

	size_backup = size(pList, 0);
	cout << size(pList, 0) << ' ' << size_backup << endl;
	cout << begin(pList).pThis->value << ' ' << end(pList).front->value << endl;

	cout << "\n list \n" << endl;
	list<int> _testList;
	for (int i = 1; i < 9; i++)
		_testList.push_back((i + 1) * 10);
	//for (auto itr = _testList.begin(); itr != _testList.end(); ++itr)
		//cout << *itr << endl;
	for(int i : _testList)
	{
		cout << i << endl;
	}
	cout << _testList.size() << ' ' << *_testList.begin() << ' ' << *(--_testList.end()) << endl;

	system("pause");
	return 0;
}

void push_back(int _value, Node* node)
{
	if (node->back != nullptr)
		push_back(_value, node->back);
	else
	{
		Node* backNode = new Node;
		backNode->front = node;
		backNode->value = _value;
		backNode->back = nullptr;
		node->back = backNode;
	}
}

Node* front(Node* node)
{
	return node;
}

Node* back(Node* _pList)
{
	if(_pList->back != nullptr)
		back(_pList->back);
	else return _pList;
}

void Delete(int _where, Node* _pList)
{
	if (_where == 0)
	{
		if (_pList->front == nullptr && _pList->back == nullptr)
		{
			delete _pList;
		}
		else if (_pList->front == nullptr)
		{
			_pList->value = _pList->back->value;
			_pList->back = _pList->back->back;
			_pList->back->back->front = _pList;
		}
		else if (_pList->back == nullptr)
		{
			_pList->front->back = nullptr;
			delete _pList;
		}
		else
		{
			_pList->front->back = _pList->back;
			_pList->back->front = _pList->front;
			delete _pList;
		}
	}
	else
		Delete(_where + (-1), _pList->back);
}

Node* erase(int _where, Node * _pList)
{
	if (_where == 0)
	{
		Node* next = _pList->back;
		_pList->front->back = next; //front 기능을 쓰지 않는다면 없어도 됨
		next->front = _pList->front;
		delete _pList;
		return next;
	}
	else
	{
		erase(--_where, _pList->back);
	}
	//return nullptr;
}

int size(Node * _pList, int _count)
{
	if (_pList != nullptr)
		size(_pList->back, ++_count);
	else
		return _count;
}

iIterator begin(Node * _pList)
{
	iIterator* itr = new iIterator;
	itr->front = nullptr;
	itr->pThis = _pList;
	itr->back = _pList->back;
	return *itr;
}

iIterator end(Node * _pList)
{
	iIterator* itr = new iIterator;
	itr->front = back(_pList);
	itr->pThis = back(_pList)->back;
	itr->back = nullptr;
	return *itr;
}
