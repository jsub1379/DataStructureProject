#include "Queue.h"
#include "Stack.h"
#include "System.h"

#include <iostream>
#include <cstring>

bool mainMenu(Queue<char>& queue, Stack<char>& undoStack, Stack<char>& redoStack) {
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

void input(Queue<char>& queue, Stack<char>& undoStack)
{
    char input[100];
	std::cin >> input;

    for (int ix = 0; ix < strlen(input); ix++)
    {
        char c = input[ix];
        queue.Enqueue(c);
    }

    while (!queue.IsEmpty())
    {
        char data;
        if (queue.Dequeue(data) == true)
            undoStack.Push(data);
    }

    std::cout << "job : ";
    undoStack.Print();
    std::cout << "\n";

}

void undo(Stack<char>& undoStack, Stack<char>& redoStack)
{
    char data;
    if (undoStack.Pop(data) == true)
        redoStack.Push(data);
    std::cout << "undo\n";
    std::cout << "job : ";
    undoStack.Print();
    std::cout << "\n";
}

void redo(Stack<char>& undoStack, Stack<char>& redoStack)
{
    char data;
    if (redoStack.Pop(data) == true)
        undoStack.Push(data);
    std::cout << "redo\n";
    std::cout << "job : ";
    undoStack.Print();
    std::cout << "\n";
}

void show(Stack<char>& undoStack, Stack<char>& redoStack)
{
    std::cout << "undo stack : ";
    while (!undoStack.IsEmpty())
    {
        undoStack.Print();
    }

    std::cout << "\n";

    std::cout << "redo stack : ";
    while (!redoStack.IsEmpty())
    {
        redoStack.Print();
    }

}