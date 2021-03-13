#pragma once

template<typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	
	Node* head = nullptr, *rear = nullptr;
	int size = 0;
	
	Node* createNode(T element)
	{
		Node* temp = new Node;
		temp->data = element;
		temp->next = temp->prev = nullptr;
		size++;
		return temp;
	}

	//Auxiliary function
	void swap(T* xp, T* yp);

public:
	void append(T element);
	void insert(T element, int index);
	T indexRemove(int index);
	T keyRemove(T key);
	int search(T key);
	void sort();
	bool isSorted();
	void print();
	const int length();
};

