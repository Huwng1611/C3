#pragma once
#include <iostream>
using namespace std;
#include "NodeStruct.h"
template <class T>

class StackPointer
{
public:
	StackPointer()
	{
		top = 0;
	}
	~StackPointer()
	{

	}

	void Push(T value)
	{
		NodeStruct<T>* new_node = new NodeStruct<T>;
		new_node->data = value;
		new_node->next = top;
		top = new_node;
	}

	//delete an element in stack and return new top item in stack
	T Pop()
	{
		if (IsEmpty())
		{
			cout << "Error: Stack is empty!" << endl;
			return NULL;
		}
		T top_element = top->data;
		NodeStruct<T>* top_ptr = top;
		top = top->next;
		delete top_ptr;
		return top_element;
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
