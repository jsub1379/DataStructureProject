#pragma once
#include <iostream>
class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual const char* Name() = 0;
    virtual void Execute() = 0;
    virtual void Undo() = 0;
    friend std::ostream& operator<<(std::ostream& os, ICommand* cmd) {
        return os << cmd->Name();
    }

private:

};

class CommandA :public ICommand
{
public:
    const char* Name() override { return "CommandA"; }
    void Execute() override { std::cout << Name() << "실행 \n"; }
    void Undo() override { std::cout << Name() << "취소 \n"; }

private:

};

class CommandB :public ICommand
{
    const char* Name() override { return "CommandB"; }
    void Execute() override { std::cout << Name() << "실행 \n"; }
    void Undo() override { std::cout << Name() << "취소 \n"; }

private:

};

class CommandC :public ICommand
{
    const char* Name() override { return "CommandC"; }
    void Execute() override { std::cout << Name() << "실행 \n"; }
    void Undo() override { std::cout << Name() << "취소 \n"; }

private:

};

class CommandD :public ICommand
{
    const char* Name() override { return "CommandD"; }
    void Execute() override { std::cout << Name() << "실행 \n"; }
    void Undo() override { std::cout << Name() << "취소 \n"; }

private:

};

class CommandE :public ICommand
{
    const char* Name() override { return "CommandE"; }
    void Execute() override { std::cout << Name() << "실행 \n"; }
    void Undo() override { std::cout << Name() << "취소 \n"; }

private:

};

//전방 선언
template <typename T> class Queue;
template <typename T> class Stack;
const int dataCount = 6;//0번 칸은 항상 비우므로 원하는 크기 +1

bool mainMenu(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack);
void input(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack);
void undo(Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack);
void redo(Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack);
void show(Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack);
void clear(Queue<ICommand*>& queue, Stack<ICommand*>& undoStack, Stack<ICommand*>& redoStack);

ICommand* makeCommand(char command);