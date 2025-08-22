#include "System.h"
#include "Stack.h"
#include "Queue.h"

int main()
{

	Queue<ICommand*> inputQueue;
	Stack<ICommand*> undoStack;
	Stack<ICommand*> redoStack;
	bool isEnd = false;


	while (!isEnd)
	{
		isEnd = mainMenu(inputQueue, undoStack, redoStack);
		
	}

}

