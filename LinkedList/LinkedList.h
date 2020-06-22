#pragma once
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;
#include "Node.h"

template <typename T>

class  LinkedList
{
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	LinkedList()
	{
		this->head = NULL;
		this->tail = NULL;
	}

	//front
	void PushFront(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (IsEmpty())
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			newNode->next = head;
			this->head = newNode;
		}
		this->size++;
	}

	bool PopFront()
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			if (this->head == this->tail)
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
			}
			else
			{
				Node<T>* temp = head;
				head = head->next;
				delete temp;
			}
			this->size--;
			return true;
		}
	}

	T TopFront() const
	{
		return this->head->value;
	}

	//back
	void PushBack(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		if (IsEmpty())
		{
			this->head = newNode;
			this->tail = newNode;
		}
		else
		{
			this->tail->next = newNode;
			this->tail = newNode;
		}
		this->size++;
	}

	T TopBack() const
	{
		return this->tail->value;
	}

	bool PopBack()
	{
		if (IsEmpty())
		{
			return false;
		}
		else
		{
			if (this->head == this->tail)
			{
				delete this->head;
				this->head = NULL;
				this->tail = NULL;
			}
			else
			{
				Node<T>* temp = this->head;
				while (temp->next->next != NULL)
				{
					temp = temp->next;
				}
				this->tail = temp;
				delete temp->next;
				temp->next = NULL;
			}
			this->size--;
			return true;
		}
	}

	int Size() const
	{
		return this->size;
	}

	bool IsEmpty() const
	{
		return this->head == NULL;
	}

	void PrintAll() const
	{
		Node<T>* temp = head;
		while (temp)
		{
			cout << temp->value << "_";
			temp = temp->next;
		}
		cout << endl;
	}

	~LinkedList() {}
};
#endif // LINKEDLIST
