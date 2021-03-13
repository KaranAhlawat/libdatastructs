#pragma once

template<typename T, int N>
class ArrayList
{
private:
	const int MAX_SIZE = N;
	T* array_list;
	int size = 0;

	void swap(T* xp, T* yp);

public:
	ArrayList();
	~ArrayList();

	void append(T element);
	void insert(T element, int index);
	T get(int index);
	void set(T element, int index);
	int search(T key);
	T indexRemove(int index);
	T keyRemove(T key);
	void sort();
	void print();
	bool isSorted();
	const int length();	
};

