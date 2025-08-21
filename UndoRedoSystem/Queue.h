#pragma once
#include <WIndows.h>

template <typename T>
class Queue
{
public:
	Queue() = default;
	~Queue() = default;

	bool IsEmpty()
	{
		if (front == rear)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if ((rear + 1) % dataCount == dataCount)
			return true;
		else
			return false;
	}

	void Enqueue(T inputdata)
	{
		if (!IsFull)
		{
			//모듈러, 원형 큐 구현
			rear = (rear + 1) % dataCount;
			data[rear] = inputdata;
	
		}
		else
		{
			MessageBoxA(nullptr, "Queue is full", "Enqueue Error", MB_OK);
			cout << "enqueue error\n";
		}
	}

	T Dequeue()
	{
		if (!IsEmpty)
		{
			front = (front + 1) % dataCount;
			return data[front];
		}
		else
		{
			MessageBoxA(nullptr, "Queue is empty", "dequeue Error", MB_OK);
			cout << "enqueue error\n";
		}
	}
private:
	T data[dataCount] = {};
	int front = 0;
	int rear = 0; //마지막 다음 칸
};