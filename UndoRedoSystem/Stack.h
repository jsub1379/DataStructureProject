#pragma once
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
			MessageBoxA(nullptr, "Stack is full", "Push error", MB_OK)
			cout << "push error\n";
		}

	}

	T Pop()
	{
		if (!IsEmpty()) 
		{
			return data[count];
			--count;
		}
		else
		{
			MessageBoxA(nullptr, "Stack is empty", "Pop error", MB_OK)
			cout << "pop error\n";
			return -1;
		}
	}


private:
	T data[dataCount] = { };

	int count = 0;
};
