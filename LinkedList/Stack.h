#pragma once
#include<iostream>
using namespace std;

#define MAX_SIZE 100

class Stack
{
public:
	Stack()
	{
		top = -1;
	}
	~Stack()
	{
	}

	void Push(int element)
	{
		if (top == MAX_SIZE - 1) //stack overflow exception
		{
			cout << "Error: Stack overflow exception" << endl;
			return;
		}
		Array[++top] = element;
	}

	void Pop()
	{
		if (IsEmpty())
		{
			cout << "Error: Stack is empty" << endl;
		}
		top--;
	}

	//Get element at top of stack
	int GetTopElement()
	{
		return Array[top];
	}

	bool IsEmpty()
	{
		return top == -1;
	}

	void ShowAllElementOfStack()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << Array[i] << " ";
		}
		cout << endl;
	}

private:
	int Array[MAX_SIZE];
	int top;
};