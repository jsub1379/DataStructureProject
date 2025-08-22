#include "Queue.h"
#include "Stack.h"
#include "System.h"

#include <iostream>
#include <cstring>



bool mainMenu(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack) {
    char selectedMenu;
    std::cout << "input(i)/undo(u)/redo(r)/show(s)/종료는 아무 키\n";
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

//todo: 만약 중간에 새로 입력한 경우는?

void input(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack)
{
    char input[100];
    std::cin >> input;
    ICommand* cmdPtr = nullptr;

    //받은 입력으로 객체 생성해서 큐에 넣음
    for (int ix = 0; ix < strlen(input); ix++)
    {
        char c = input[ix];
        //여기서 객체 생성
        cmdPtr = makeCommand(c);
        queue.Enqueue(cmdPtr);
    }

    //큐에서 꺼내서 실행하고, undo에 기록
    while (!queue.IsEmpty())
    {
        //todo:null인 경우에 처리
        if (queue.Dequeue(cmdPtr) == true)
        {
            cmdPtr->Execute();
            undoStack.Push(cmdPtr);
        }
    }
    //todo: redo 초기화하기

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