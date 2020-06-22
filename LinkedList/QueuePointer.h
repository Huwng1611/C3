#pragma once
#include <iostream>
using namespace std;
#include "NodeStruct.h"
template <class T>

class  QueuePointer
{
public:
	QueuePointer()
	{
		top = 0;
	}
	~QueuePointer()
	{

	}

	void EnQueue(T value)
	{
		NodeStruct<T>* new_node = new NodeStruct<T>;
		new_node->data = value;
		new_node->next = 0;
		if (IsEmpty())
		{
			top = new_node;
		}
		else
		{
			NodeStruct<T>* temp = top;
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	T Dequeue()
	{
		if (IsEmpty())
		{
			cout << "Error: Queue is empty!" << endl;
			return NULL;
		}
		T element = top->data;
		NodeStruct<T>* temp = top;
		top = top->next;
		delete temp;
		return element;
	}

	bool IsEmpty() const
	{
		return top == 0;
	}

	void ShowAllElements()
	{
		NodeStruct<T>* temp = top;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

private:
	NodeStruct<T>* top;
};