#pragma once

//전방 선언
template <typename T> class Queue;
template <typename T> class Stack;

const int dataCount = 5;

bool mainMenu(Queue<char>& queue, Stack<char>& undoStack, Stack<char>& redoStack);
void input(Queue<char>& queue, Stack<char>& undoStack);
void undo(Stack<char>& undoStack, Stack<char>& redoStack);
void redo(Stack<char>& undoStack, Stack<char>& redoStack); 
void show(Stack<char>& undoStack, Stack<char>& redoStack);