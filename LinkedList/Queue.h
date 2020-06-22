#include <iostream>
using namespace std;

#define MAX_SIZE 100

class  Queue
{
public:
	Queue()
	{
		front = -1;
		rear = -1;
	}
	~Queue() {}

	bool IsEmpty()
	{
		return (front == -1 && rear == -1);
	}

	bool IsFull()
	{
		return (rear + 1) % MAX_SIZE == front ? true : false;
	}

	//insert an element in queue at rear
	void EnQueue(int element)
	{
		if (IsFull())
		{
			cout << "Queue is full" << endl;
			return;
		}
		else
		{
			if (IsEmpty())
			{
				front = rear = 0;
			}
			else
			{
				rear = (rear + 1) % MAX_SIZE;
			}
		}
		Array[rear] = element;
	}

	//remove an element in queue at front
	void DeQueue()
	{
		if (IsEmpty())
		{
			cout << "Queue is empty" << endl;
			return;
		}
		else
		{
			if (front == rear)
			{
				front = rear = -1;
			}
			else
			{
				front = (front + 1) % MAX_SIZE;
			}
		}
	}

	//Return an element at front of queue
	int ElementAtFront()
	{
		if (IsEmpty()) // == front = -1;
		{
			return -1;
		}
		return Array[front];
	}

	void ShowAllElements()
	{
		//int queue_length = sizeof(Array) / sizeof(Array[0]);
		int queue_length = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
		cout << "Queue_length = " << queue_length << endl;
		for (int i = 0; i < queue_length; i++)
		{
			int index = (front + i) % MAX_SIZE;
			cout << Array[index] << " ";
		}
	}


private:
	int Array[MAX_SIZE];
	int front;
	int rear;
};