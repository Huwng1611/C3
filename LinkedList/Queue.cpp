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


private:
	int Array[MAX_SIZE];
	int front;
	int rear;
};