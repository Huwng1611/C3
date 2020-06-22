#pragma once
#include <iostream>
using namespace std;
#include "NodeStruct.h"
template<class T>

class ListPointer
{
public:
	ListPointer()
	{
		head = 0;
	}
	~ListPointer()
	{
	}

	ListPointer(ListPointer<T> list, int from, int to)
	{
		head = 0;
		NodeStruct<T>* temp = list.head;
		for (int i = 1; i < from; i++)
		{
			temp = temp->next;
		}
		for (int i = from; i <= to; i++)
		{
			PushBack(temp->data);
			temp = temp->next;
		}
	}

	ListPointer(const ListPointer<T>& list)
	{
		head = 0;
		NodeStruct<T>* temp = list.head;
		while (temp != 0)
		{
			PushBack(temp->data);
			temp = temp->next;
		}
	}

	int Length() const
	{
		int length = 0;
		NodeStruct<T>* temp = head;
		while (temp != 0)
		{
			temp = temp->next;
			length++;
		}
		return length;
	}

	void PushBack(T value)
	{
		NodeStruct<T>* new_node = new NodeStruct<T>;
		new_node->data = value;
		new_node->next = 0;
		if (head == 0)
		{
			head = new_node;
		}
		else
		{
			NodeStruct<T>* temp = head;
			while (temp->next != 0)
			{
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	void PushTop(T value)
	{
		NodeStruct<T>* new_node = new NodeStruct<T>;
		new_node->data = value;
		new_node->next = head;
		head = new_node;
	}

	void ShowAllElements() const
	{
		NodeStruct<T>* temp = head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	T GetItemByIndex(int index)
	{
		if (index == 0)
		{
			return head->data;
		}
		else
		{
			NodeStruct<T>* temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			return temp->next->data;
		}
	}

	void DeleteItemByIndex(int index)
	{
		if (index > Length() - 1)
		{
			cout << "Error: index is out of range!" << endl;
			return;
		}
		else
		{
			if (index == 0)
			{
				NodeStruct<T>* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				NodeStruct<T>* temp = head;
				for (int i = 0; i < index - 1; i++)
				{
					temp = temp->next;
				}
				NodeStruct<T>* node_next_to_temp = temp->next;
				temp->next = temp->next->next;
				delete node_next_to_temp;
			}
		}
	}

	void DeleteItemByValue(T value)
	{
		if (HasValue(value))
		{
			if (head->data == value)
			{
				NodeStruct<T>* temp = head;
				head = head->next;
				delete temp;
			}
			else
			{
				NodeStruct<T>* temp = head;
				while (temp->next != 0)
				{
					if (temp->next->data == value)
					{
						NodeStruct<T>* temp_next = temp->next;
						temp->next = temp->next->next;
						delete temp_next;
					}
					else
					{
						temp = temp->next;
					}
				}
			}
		}
		else
		{
			cout << "Error: List not contain this value: " << value << endl;
			return;
		}
	}

	void ChangeValueAnElement(T value, int index)
	{
		if (index < Length() - 1 && index != 0)
		{
			NodeStruct<T>* temp = head;
			for (int i = 0; i < index - 1; i++)
			{
				temp = temp->next;
			}
			temp->data = value;
		}
		else
		{
			cout << "Error: Index is out of range!" << endl;
			return;
		}
	}

	void InsertAnElement(T value, int index)
	{
		if (index < Length() - 1)
		{
			if (index == 1)
			{
				PushTop(value);
			}
			else
			{
				NodeStruct<T>* new_node = new NodeStruct<T>;
				new_node->data = value;
				NodeStruct<T>* temp = head;
				for (int i = 0; i < index - 1; i++)
				{
					temp = temp->next;
				}
				new_node->next = temp->next;
				temp->next = new_node;
			}
		}
		else
		{
			cout << "Error: Index is out of range!" << endl;
			return;
		}
	}

	void SearchAnElement(int value)
	{
		if (HasValue(value))
		{
			NodeStruct<T>* temp = head;
			int index = 0;
			while (temp != 0)
			{
				if (temp->data == value)
				{
					cout << "Phan tu can tim co vi tri: " << index + 1 << endl;
					break;
				}
				else
				{
					//continue loop
					temp = temp->next;
					index++;
				}
			}
			return;
		}
		else
		{
			cout << "Error: List not contain this value: " << value << endl;
			return;
		}
	}

	bool HasValue(T value)
	{
		NodeStruct<T>* temp = head;
		while (temp != 0)
		{
			if (temp->data == value)
			{
				return true;
			}
			else
			{
				//continue loop
				temp = temp->next;
			}
		}
		return false;
	}

	void ReverseList()
	{
		NodeStruct<T>* temp = 0;
		NodeStruct<T>* temp_head = head;
		while (temp_head != 0)
		{
			NodeStruct<T>* new_node = new NodeStruct<T>;
			new_node->data = temp_head->data;
			new_node->next = temp;
			temp = new_node;
			NodeStruct<T>* new_temp_head = temp_head;
			temp_head = temp_head->next;
			delete new_temp_head;
		}
	}

	ListPointer<T> operator = (const ListPointer<T>& list)
	{
		head = 0;
		NodeStruct<T>* temp = list.head;
		while (temp != 0)
		{
			PushBack(temp->data);
			temp = temp->next;
		}
		return *this;
	}

private:
	NodeStruct<T>* head;
};