#include <iostream>

using namespace std;

typedef struct tagNode
{
public:
	tagNode* front = nullptr;
	int value = 0;
	tagNode* back = nullptr;
}Node;

void push_back(int value, Node* node);
Node* front(Node* node);
Node* back(Node* _pList);
void Delete(int _where, Node* _pList);

int main()
{
	Node* pList = new Node;
	pList->value = 10;
	for(int i = 1; i < 4; i++)
		push_back((i + 1) * 10, pList);

	Delete(0, pList);
	//Delete(2, pList);

	cout << front(pList)->value << endl;
	cout << back(pList->back)->value << endl;

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