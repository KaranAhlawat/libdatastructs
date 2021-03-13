#pragma once

template<typename T>
class Stack
{
private:
	T* stack = nullptr;
	int size = 0;
	int max_size = 5;
	void resize();

public:
	Stack();
	~Stack();

	void push(T element);
	T pop();
	const int getSize();
	const int curMaxSize();
	void print();
};

