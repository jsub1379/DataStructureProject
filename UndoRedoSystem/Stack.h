#pragma once
#include "System.h"

#include <iostream>
#include <Windows.h>
template <typename T>

class Stack
{
public:
	Stack() = default;
	~Stack() = default;

	bool IsEmpty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}
	bool IsFull()
	{
		if (count == dataCount)
			return true;
		else
			return false;
	}

	void Push(T inputdata)
	{
		if (!IsFull())
		{
			data[count] = inputdata;
			++count;
		}
		else
		{
			MessageBoxA(nullptr, "Stack is full", "Push error", MB_OK);
			std::cout << "push error\n";
		}

	}

	bool Pop(T& returnData)
	{
		if (!IsEmpty()) 
		{
			--count;
			returnData = data[count];
			return true;
		}
		else
		{
			//todo:여기도 반환값 오류
			MessageBoxA(nullptr, "Stack is empty", "Pop error", MB_OK);
			std::cout << "pop error\n";
			return false;
		}
	}

	void Print()
	{
		for (int ix = 0; ix < count; ix++)
		{
			std::cout << data[ix] << " ";
		}
	}

private:
	T data[dataCount] = { };

	int count = 0;
};
