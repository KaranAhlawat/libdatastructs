#include <iostream>
#include "LinkedList.h"

template<typename T>
void LinkedList<T>::swap(T* xp, T* yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template<typename T>
void LinkedList<T>::append(T element)
{
	Node* node = createNode(element);
	
	if (head == nullptr)
	{
		head = rear = node;
		return;
	}

	rear->next = node;
	node->prev = rear;
	rear = node;
	return;
}

template<typename T>
void LinkedList<T>::insert(T element, int index)
{
	if (index == size)
	{
		append(element);
		return;
	}

	Node* node = createNode(element);

	if (head == nullptr)
	{
		head = rear = node;
		return;
	}

	if (index > size)
	{
		std::cout << "Cannot insert at given index" << std::endl;
		return;
	}

	Node* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}

	node->next = temp;
	node->prev = temp->prev;
	if (index != 0)
	{
		temp->prev->next = node;
	}
	temp->prev = node;
	if (index == 0)
	{
		head = node;
	}
}

template<typename T>
int LinkedList<T>::search(T key)
{
	Node* temp = head;
	for (int i = 0; i < size; i++)
	{
		if (temp->data == key)
		{
			return i;
		}
		temp = temp->next;
	}
	return -1;
}

template<typename T>
T LinkedList<T>::indexRemove(int index)
{
	if (head == nullptr)
	{
		std::cout <<  "Underflow" << std::endl;
		return T();
	}

	else if (index >= size)
	{
		std::cout << "Invalid index" << std::endl;
		return T();
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}

		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		T val = temp->data;
		delete temp;
		size--;
		return val;
	}
}

template<typename T>
T LinkedList<T>::keyRemove(T element)
{
	int index = search(element);
	if (index != -1)
	{
		return indexRemove(index);
	}
	else
	{
		std::cout << "Key not found" << std::endl;
		return T();
	}
}

template<typename T>
void LinkedList<T>::sort()
{
	int swapped;
	Node* ptr1;
	Node* lptr = nullptr;

	if (head == nullptr)
		return;

	do
	{
		swapped = 0;
		ptr1 = head;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(&(ptr1->data), &(ptr1->next->data));
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

template<typename T>
bool LinkedList<T>::isSorted()
{
	if (head == nullptr || head == rear)
	{
		return true;
	}
	
	Node* temp = head;
	for (int i = 0; i < size - 1; i++)
	{
		if (temp->data > temp->next->data)
		{
			return false;
		}
		temp = temp->next;
	}
	return true;
}

template<typename T>
const int LinkedList<T>::length()
{
	return size;
}

template<typename T>
void LinkedList<T>::print()
{
	std::cout << "Current list is : " << std::endl;
	Node* temp = head;
	for (int i = 0; i < size; i++)
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
	std::cout << std::endl;
}

