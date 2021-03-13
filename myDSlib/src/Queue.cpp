#include <iostream>
#include "Queue.h"

template<typename T>
void Queue<T>::resize()
{
	T* temp = new T[2 * max_size];
	for (int i = front; i < front + size; i++)
	{
		temp[i - front] = queue[i];
	}
	max_size *= 2;
	rear -= front;
	front = 0;
	delete[] queue;
	queue = temp;
}

template<typename T>
Queue<T>::Queue()
{
	queue = new T[max_size];
}

template<typename T>
Queue<T>::~Queue()
{
	delete[] queue;
}

template<typename T>
void Queue<T>::enqueue(T element)
{
	size++;
	if (size == max_size)
	{
		resize();
	}
	if (size == 1)
	{
		queue[++front] = element;
		rear = 0;
		return;
	}
	if (rear == max_size - 1)
	{
		resize();
	}
	queue[++rear] = element;
	return;
}

template<typename T>
T Queue<T>::dequeue()
{
	size--;
	if (front == rear)
	{
		T val = queue[front];
		front = rear = -1;
		return val;
	}
	return queue[front++];
}

template<typename T>
const int Queue<T>::curMaxSize() const
{
	return max_size;
}

template<typename T>
const int Queue<T>::getSize() const
{
	return size;
}

template<typename T>
const T Queue<T>::getFront() const
{
	return queue[front];
}

template<typename T>
const T Queue<T>::getRear() const
{
	return queue[rear];
}

template<typename T>
void Queue<T>::print()
{
	std::cout << "Current queue is : " << std::endl;
	for (int i = front; i <= rear ; i++)
	{
		std::cout << queue[i] << std::endl;
	}
}