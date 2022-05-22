#include "LinkedList.h"
#include <iostream>
#include <limits>
using namespace std;

LinkedList::LinkedList()
	: head(nullptr)
{
}

LinkedList::LinkedList(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		addEnd(arr[i]);
	}
}

LinkedList::~LinkedList()
{
	while (head)
	{
		deleteEnd();
	}
}

void LinkedList::addFront(int newItem)
{
	Node* n = new Node();
	n->setData(newItem);
	n->setNext(head);
	head = n;
}

void LinkedList::addEnd(int newItem)
{
	if (!head)
	{
		head = new Node();
		head->setData(newItem);
	}
	else
	{
		Node* n = head;
		while (n->getNext())
		{
			n = n->getNext();
		}
		n->setNext(new Node());
		n = n->getNext();
		n->setData(newItem);
	}
}

void LinkedList::addAtPosition(int position, int newItem)
{
	int count = 0;
	Node* n = head;
	while (n)
	{
		++count;
		n = n->getNext();
	}

	if (position <= 1)
	{
		addFront(newItem);
	}
	else
	{
		if (position > count)
		{
			addEnd(newItem);
		}
		else
		{
			count = 1;
			n = head;
			while (count < position - 1)
			{
				++count;
				n = n->getNext();
			}

			Node* nn = n->getNext();
			Node* p = new Node();
			p->setData(newItem);
			p->setNext(nn);
			n->setNext(p);
		}
	}
}

int LinkedList::search(int item)
{
	bool have = false;
	int count = 1;
	Node* n = head;
	while (n)
	{
		if (n->getData() == item)
		{
			have = true;
			break;
		}
		else
		{
			++count;
			n = n->getNext();
		}
	}

	if (have)
	{
		cout << count << " ";
		return count;
	}
	else
	{
		cout << "0 ";
		return 0;
	}
}

void LinkedList::deleteFront()
{
	if (head)
	{
		Node* n = head->getNext();
		delete head;
		head = n;
	}
}

void LinkedList::deleteEnd()
{
	if (head)
	{
		int count = 0;
		Node* n = head;
		while (n)
		{
			++count;
			n = n->getNext();
		}

		if (count > 1)
		{
			int c = 0;
			n = head;
			while (c < count - 1)
			{
				++c;
				n = n->getNext();
			}

			delete n;

			c = 0;
			n = head;
			while (c < count - 2)
			{
				++c;
				n = n->getNext();
			}

			n->setNext(nullptr);
		}
		else
		{
			delete head;
			head = nullptr;
		}
	}
}

void LinkedList::deletePosition(int position)
{
	int count = 1;
	Node* n = head;
	while (n)
	{
		++count;
		n = n->getNext();
	}

	if (position < 1 || position > count)
	{
		cout << "out of range" << endl;
		return;
	}

	Node* pNewHead = nullptr;
	Node* pTemp = head;
	Node* pDel = nullptr;
	int nCount = 1;

	if (head == nullptr)
	{
		return;
	}

	if (position == 1)
	{
		pNewHead = pTemp->getNext();

		delete pTemp;

		if (pNewHead == nullptr)
		{
			head = nullptr;
		}
		else
		{
			head = pNewHead;
		}

		return;
	}

	nCount++;

	while (pTemp)
	{
		if (position == nCount)
		{
			pDel = pTemp->getNext();
			pTemp->setNext(pTemp->getNext()->getNext());
			delete pDel;
			return;
		}
		else
		{
			pTemp = pTemp->getNext();
			nCount++;
		}
	}
}

int LinkedList::getItem(int position)
{
	int count = 1;
	Node* n = head;
	while (n)
	{
		++count;
		n = n->getNext();
	}

	n = head;
	for (int i = 1; i <= position; i++)
	{
		if (i == position)
		{
			if (i < count)
			{
				if (n)
				{
					cout << n->getData() << " ";
				}
				else
				{
					cout << numeric_limits<int>::max() << " ";
				}
			}
			else
			{
				cout << numeric_limits<int>::max() << " ";
				return numeric_limits<int>::max();
			}
		}

		if (n)
		{
			n = n->getNext();
		}
	}
}

void LinkedList::printItems()
{
	Node* n = head;
	while (n)
	{
		cout << n->getData() << " ";
		n = n->getNext();
	}
}
