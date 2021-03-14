#include <iostream>
#include "ArrayList.h"

template<typename T, int N>
void ArrayList<T, N>::swap(T* xp, T* yp)
{
	T temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template<typename T, int N>
ArrayList<T, N>::ArrayList()
{
	array_list = new T[MAX_SIZE];
}

template<typename T, int N>
ArrayList<T, N>::~ArrayList()
{
	delete[] array_list;
}

template<typename T, int N>
void ArrayList<T, N>::append(T element)
{
	if (size < MAX_SIZE)
	{
		array_list[size++] = element;
	}
	else
		std::cout << "Overflow" << std::endl;
}

template<typename T, int N>
void ArrayList<T, N>::insert(T element, int index)
{
	if (size < MAX_SIZE)
	{
		for (int i = size - 1; i >= index; i--)
			array_list[i + 1] = array_list[i];
		array_list[index] = element;
		size++;
	}
	else
		std::cout << "Overflow" << std::endl;
}

template<typename T, int N>
T ArrayList<T, N>::get(int index)
{
	if (index >= size)
	{
		std::cout << "Invalid index. Cannot get." << std::endl;
		return T();
	}
	return array_list[index];
}

template<typename T, int N>
void ArrayList<T, N>::set(T element, int index)
{
	if (index >= size)
	{
		std::cout << "Invalid index. Cannot set." << std::endl;
		return;
	}
	array_list[index] = element;
	return;
}

template<typename T, int N>
int ArrayList<T, N>::search(T key)
{
	for (int i = 0; i < size; i++)
	{
		if (array_list[i] == key)
			return i;
	}
	return -1;
}

template<typename T, int N>
T ArrayList<T, N>::indexRemove(int index)
{
	if (size == 0)
	{
		std::cout << "Underflow" << std::endl;
		return T();
	}
	else if (index >= size)
	{
		std::cout << "Invalid index" << std::endl;
		return T();
	}
	else
	{
		T data = array_list[index];
		for (int i = index; i < size - 1; i++)
			array_list[i] = array_list[i + 1];
		size--;
		return data;
	}
}

template<typename T, int N>
T ArrayList<T, N>::keyRemove(T key)
{	
	int index = search(key);
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

template<typename T, int N>
void ArrayList<T, N>::sort()
{
	if (!isSorted())
	{
		int i, j;
		for (i = 0; i < size - 1; i++)
			for (j = 0; j < size - i - 1; j++)
				if (array_list[j] > array_list[j + 1])
					swap(&array_list[j], &array_list[j + 1]);
	}
	return;
}

template<typename T, int N>
void ArrayList<T, N>::print()
{
	if (size == 0)
	{
		std::cout << "Underflow" << std::endl;
		return;
	}
	std::cout << "\nCurrent list is : " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << array_list[i] << "\t";
	}
}

template<typename T, int N>
bool ArrayList<T, N>::isSorted()
{
	if (size == 1 || size == 0)
		return true;
	else
	{
		int i = 0;
		while (i < size - 1)
		{
			if (array_list[i] > array_list[i + 1])
				return false;
			i++;
		}
	}
	
}

template<typename T, int N>
const int ArrayList<T, N>::length()
{
	return size;
}
