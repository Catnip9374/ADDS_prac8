#include "Node.h"

Node::Node()
	: data(), next(nullptr)
{
}

void Node::setData(int d)
{
	data = d;
}

void Node::setNext(Node* n)
{
	next = n;
}

int Node::getData()
{
	return data;
}

Node* Node::getNext()
{
	return next;
}
