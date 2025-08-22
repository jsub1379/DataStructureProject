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
        input(queue, undoStack, redoStack);
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


void input(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack,Stack<ICommand*>& redoStack)
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

        if (cmdPtr == nullptr)
        {
            MessageBoxA(nullptr, "Unknown Command", "menu error", MB_OK);
            std::cout << "unknown command.\n";
        }
        else
            queue.Enqueue(cmdPtr);

    }

    //ť���� ������ �����ϰ�, undo�� ���
    while (!queue.IsEmpty())
    {
        if (queue.Dequeue(cmdPtr) == true)
        {
            cmdPtr->Execute();
            undoStack.Push(cmdPtr);
        }
    }

    while (!redoStack.IsEmpty())
    {
        ICommand* ptr = nullptr;
        redoStack.Pop(ptr);
    }
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

//todo: �޸� ���� ����
void clear(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack)
{
    //ICommand* p = nullptr;
    //while (!queue.Dequeue(p)) { delete p; }
    //while (!undoStack.Pop(p)) { delete p; }
    //while (!redoStack.Pop(p)) { delete p; }
}