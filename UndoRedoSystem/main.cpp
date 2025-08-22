#include "System.h"
#include "Stack.h"
#include "Queue.h"

int main()
{

	Queue<ICommand*> inputQueue;
	Stack<ICommand*> undoStack;
	Stack<ICommand*> redoStack;
	bool isEnd = false;

	std::cout << "정의한 명령어: a b c d e \n최대로 받을수 있는 명령어 개수 (큐,스택 크기) : 5\n";
	while (!isEnd)
	{

		
		isEnd = mainMenu(inputQueue, undoStack, redoStack);
		
	}

	clear(inputQueue,undoStack,redoStack);

}

