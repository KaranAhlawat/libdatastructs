#pragma once

template<typename T>
class Queue
{
private:
	T* queue = nullptr;
	int size = 0;
	int front = -1, rear = -1;
	int max_size = 5;
	void resize();

public: 
	Queue();
	~Queue();

	void enqueue(T element);
	T dequeue();
	const int getSize() const;
	const int curMaxSize() const;
	void print();
	const T getFront() const;
	const T getRear() const;
};

