#ifndef NODE
#define NODE

class Node
{
	int data;
	Node* next;
public:
	Node();
	void setData(int d);
	void setNext(Node* n);
	int getData();
	Node* getNext();
};

#endif