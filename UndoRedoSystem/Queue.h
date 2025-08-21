#pragma once
#include "System.h"

#include <iostream>
#include <Windows.h>

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
		if ((rear + 1) % dataCount == front)
			return true;
		else
			return false;
	}

	void Enqueue(T inputdata)
	{
		if (!IsFull())
		{
			//모듈러, 원형 큐 구현
			rear = (rear + 1) % dataCount;
			data[rear] = inputdata;
	
		}
		else
		{
			MessageBoxA(nullptr, "Queue is full", "Enqueue Error", MB_OK);
			std::cout << "enqueue error\n";
		}
	}

	bool Dequeue(T& returnData)
	{
		if (!IsEmpty())
		{
			front = (front + 1) % dataCount;
			returnData = data[front];
			return true;
		}
		else
		{
			//todo:반환값이 없음
			MessageBoxA(nullptr, "Queue is empty", "dequeue Error", MB_OK);
			std::cout << "enqueue error\n";
			return false;
		}

	}

	void Print()
	{
		for (int ix = 0; ix < rear; ix++)
		{
			std::cout << data[ix] << " ";
		}
	}

private:
	T data[dataCount] = {};
	int front = 1;//첫번째 칸 비웠으므로 1부터 시작
	int rear = 1; //마지막 다음 칸
};