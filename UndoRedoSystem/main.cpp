#include "System.h"
#include "Stack.h"
#include "Queue.h"

int main()
{

	Queue<ICommand*> inputQueue;
	Stack<ICommand*> undoStack;
	Stack<ICommand*> redoStack;
	bool isEnd = false;

	std::cout << "������ ��ɾ�: a b c d e \n�ִ�� ������ �ִ� ��ɾ� ���� (ť,���� ũ��) : 5\n";
	while (!isEnd)
	{

		
		isEnd = mainMenu(inputQueue, undoStack, redoStack);
		
	}

	clear(inputQueue,undoStack,redoStack);

}

