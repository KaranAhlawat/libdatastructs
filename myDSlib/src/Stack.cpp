#include <iostream>
#include "Stack.h"

template<typename T>
void Stack<T>::resize()
{
	T* temp = new T[2 * max_size];
	for (int i = 0; i < size; i++)
	{
		temp[i] = stack[i];
	}
	max_size *= 2;
	delete[] stack;
	stack = temp;
}

template<typename T>
Stack<T>::Stack()
{
	stack = new T[max_size];
}

template<typename T>
Stack<T>::~Stack()
{
	delete[] stack;
}

template<typename T>
void Stack<T>::push(T element)
{
	if (size == max_size)
	{
		resize();
	}
	stack[size++] = element;
	return;
}

template<typename T>
T Stack<T>::pop()
{
	if (size == 0)
	{
		std::cout << "Underflow" << std::endl;
		return T();
	}
	return stack[(size--) - 1];
}

template<typename T>
const int Stack<T>::getSize()
{
	return size;
}

template<typename T>
const int Stack<T>::curMaxSize()
{
	return max_size;
}

template<typename T>
void Stack<T>::print()
{
	std::cout << "Current stack is : " << std::endl;
	for (int i = size - 1; i >= 0; i--)
	{
		std::cout << stack[i] << std::endl;
	}
}