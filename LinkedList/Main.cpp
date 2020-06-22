#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "StackPointer.h"
#include "QueuePointer.h"
#include "ListPointer.h"

void ExampleLinkedList()
{
	LinkedList<int> new_list;
	new_list.PushBack(1);
	new_list.PushBack(2);
	new_list.PushBack(10);
	new_list.PushBack(15);
	new_list.PushFront(8);
	new_list.PrintAll();
	cout << "Size = " << new_list.Size() << endl;
	cout << "Top front element = " << new_list.TopFront() << endl;
	cout << "Top back element = " << new_list.TopBack() << endl;

	cout << "===================================================================================\n";

	new_list.PopBack();
	new_list.PopFront();
	new_list.PrintAll();
	cout << "Size = " << new_list.Size() << endl;
	cout << "Top front element = " << new_list.TopFront() << endl;
	cout << "Top back element = " << new_list.TopBack() << endl;
}

void ExampleStack()
{
	Stack stack;
	stack.Push(2);
	stack.Push(4);
	stack.Push(90);
	stack.Push(28);
	stack.Push(65);
	stack.Push(23);
	stack.ShowAllElementOfStack();
	cout << "Top element = " << stack.GetTopElement() << endl;
	cout << "===================================================================================\n";
	stack.Pop();
	stack.ShowAllElementOfStack();
	cout << "Top element = " << stack.GetTopElement() << endl;
}

void ExampleQueue()
{
	Queue queue;
	queue.EnQueue(2);
	queue.EnQueue(0);
	queue.EnQueue(5);
	queue.EnQueue(9);
	queue.ShowAllElements();
	cout << endl;
	cout << "=========================================================================" << endl;
	queue.DeQueue();
	cout << "After Dequeue:" << endl;
	queue.ShowAllElements();
}

void ExampleListPointer()
{
	ListPointer<int> lsPointer;
	lsPointer.PushBack(1);
	lsPointer.PushBack(2);
	lsPointer.PushBack(3);
	lsPointer.PushBack(4);
	lsPointer.PushBack(5);
	lsPointer.PushTop(80);
	//lsPointer.ShowAllElements();
	//cout << "=========================================================================" << endl;
	//cout << "Tim value trong list:" << endl;
	//cout << "Nhap value:" << endl;
	//int value;
	//cin >> value;
	//if (lsPointer.HasValue(value))
	//{
	//	cout << "Has value: " << value << endl;
	//}
	//else
	//{
	//	cout << "Error: not contain this value: " << value << endl;
	//}
	//cout << "=========================================================================" << endl;
	//cout << "Xoa phan tu tai vi tri index:" << endl;
	//cout << "Nhap index:";
	//int index;
	//cin >> index;
	//lsPointer.DeleteItemByIndex(index);
	//cout << "List sau khi xoa 1 phan tu theo index:" << endl;
	//lsPointer.ShowAllElements();
	//cout << "=========================================================================" << endl;
	//cout << "Xoa phan tu co gia tri value:" << endl;
	//cout << "Nhap value:";
	//int delete_by_value;
	//cin >> delete_by_value;
	//lsPointer.DeleteItemByValue(delete_by_value);
	//cout << "List sau khi xoa 1 phan tu theo value:" << endl;
	//lsPointer.ShowAllElements();
	//cout << "=========================================================================" << endl;
	//cout << "Search phan tu:" << endl;
	//cout << "Nhap gia tri can search:";
	//int search_value;
	//cin >> search_value;
	//lsPointer.SearchAnElement(search_value);
	//cout << "=========================================================================" << endl;
	//cout << "Thay doi gia tri phan tu:" << endl;
	//cout << "Nhap gia tri muon thay doi:";
	//int change_value;
	//cin >> change_value;
	//cout << "Nhap index phan tu muon thay doi: ";
	//int change_index;
	//cin >> change_index;
	//lsPointer.ChangeValueAnElement(change_value, change_index);
	//cout << "List sau khi thay doi gia tri phan tu:" << endl;
	//lsPointer.ShowAllElements();
	//cout << "=========================================================================" << endl;
	//cout << "Insert phan tu:" << endl;
	//cout << "Nhap gia tri muon insert:" << endl;
	//int insert_value;
	//cin >> insert_value;
	//cout << "Nhap vi tri muon insert:" << endl;
	//int insert_index;
	//cin >> insert_index;
	//lsPointer.InsertAnElement(insert_value, insert_index);
	//lsPointer.ShowAllElements();
	//cout << "=========================================================================" << endl;
	cout << "List after reverse:" << endl;
	lsPointer.ReverseList();
	lsPointer.ShowAllElements();
}

void ExampleStackPointer()
{
	StackPointer<int> st_ptr;
	st_ptr.Push(2);
	st_ptr.Push(65);
	st_ptr.Push(1278);
	st_ptr.Push(6);
	st_ptr.Push(40);
	st_ptr.Push(85);
	st_ptr.ShowAllElements();
	cout << "=========================================================================" << endl;
	st_ptr.Pop();
	cout << "After pop: " << endl;
	st_ptr.ShowAllElements();
}

void ExampleQueuePointer()
{
	QueuePointer<int> q_ptr;
	q_ptr.EnQueue(1);
	q_ptr.EnQueue(3);
	q_ptr.EnQueue(5);
	q_ptr.EnQueue(6);
	q_ptr.EnQueue(8);
	q_ptr.ShowAllElements();
	cout << "=========================================================================" << endl;
	q_ptr.Dequeue();
	cout << "After dequeue: " << endl;
	q_ptr.ShowAllElements();
}

void TestMethod()
{
	int* ptr1;
	int a = 5;
	ptr1 = &a;
	cout << ptr1 << endl;
	cout << "========" << endl;
	int* ptr2 = ptr1;
	cout << *ptr2 << endl;
}

int main()
{
	cout << "Nhap so chon mode: " << endl;
	cout << "0.Test Method " << endl;
	cout << "1.LinkedList " << endl;
	cout << "2.StackArray " << endl;
	cout << "3.QueueArray " << endl;
	cout << "4.ListPointer " << endl;
	cout << "5.StackPointer " << endl;
	cout << "6.QueuePointer " << endl;

	int mode_number;
	cin >> mode_number;

	switch (mode_number)
	{
	case 0:
		TestMethod();
		break;
	case 1:
		ExampleLinkedList();
		break;
	case 2:
		ExampleStack();
		break;
	case 3:
		ExampleQueue();
		break;
	case 4:
		ExampleListPointer();
		break;
	case 5:
		ExampleStackPointer();
		break;
	case 6:
		ExampleQueuePointer();
		break;
	default:
		break;
	}

	return 0;
}