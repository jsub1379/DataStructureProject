#include "System.h"
#include "Stack.h"
#include "Queue.h"



int main()
{

	Queue<char> inputQueue;
	Stack<char> undoStack;
	Stack<char> redoStack;
	bool isEnd = false;

	while (!isEnd)
	{

		isEnd = mainMenu(inputQueue, undoStack, redoStack);

		

	}

}

