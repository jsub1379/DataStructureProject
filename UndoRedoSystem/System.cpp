#include "Queue.h"
#include "Stack.h"
#include "System.h"

#include <iostream>
#include <cstring>



bool mainMenu(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack) {
    char selectedMenu;
    std::cout << "input(i)/undo(u)/redo(r)/show(s)/����� �ƹ� Ű\n";
    std::cin >> selectedMenu;

    if (selectedMenu == 'i') {
        input(queue, undoStack);
        return false;
    }
    else if (selectedMenu == 'u')
    {
        undo(undoStack, redoStack);
        return false;
    }
    else if (selectedMenu == 'r')
    {
        redo(undoStack, redoStack);
        return false;
    }
    else if (selectedMenu == 's')
    {
        show(undoStack, redoStack);
        return false;
    }
    else
    {
        return true;
    }
}

//todo: ���� �߰��� ���� �Է��� ����?

void input(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack)
{
    char input[100];
    std::cin >> input;
    ICommand* cmdPtr = nullptr;

    //���� �Է����� ��ü �����ؼ� ť�� ����
    for (int ix = 0; ix < strlen(input); ix++)
    {
        char c = input[ix];
        //���⼭ ��ü ����
        cmdPtr = makeCommand(c);
        queue.Enqueue(cmdPtr);
    }

    //ť���� ������ �����ϰ�, undo�� ���
    while (!queue.IsEmpty())
    {
        //todo:null�� ��쿡 ó��
        if (queue.Dequeue(cmdPtr) == true)
        {
            cmdPtr->Execute();
            undoStack.Push(cmdPtr);
        }
    }
    //todo: redo �ʱ�ȭ�ϱ�

}

ICommand* makeCommand(char command)
{
    switch (command)
    {
    case 'a':
        return new CommandA();

    case 'b':
        return new CommandB();

    case 'c':
        return new CommandC();

    case 'd':
        return new CommandD();

    case 'e':
        return new CommandE();

    default:
        return nullptr;
    }


}


void undo(Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack)
{
    ICommand* cmdPtr;
    if (undoStack.Pop(cmdPtr) == true)
    {
        cmdPtr->Undo();
        redoStack.Push(cmdPtr);
    }

}

void redo(Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack)
{
    ICommand* cmdPtr;
    if (redoStack.Pop(cmdPtr) == true)
    {
        cmdPtr->Execute();
        undoStack.Push(cmdPtr);
    }

}


void show(Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack)
{
    std::cout << "undo stack : ";
    undoStack.Print();  
    std::cout << "\n";

    std::cout << "redo stack : ";
    redoStack.Print();  
    std::cout << "\n";
}