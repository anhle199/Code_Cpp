// File: StackCPP_T.h
// Use C++ template

#ifndef STACK_CPP_T_H_
#define STACK_CPP_T_H_

template<class T>
struct Stack {
    void *data;
};

// Print all elements of stack.
template<class T>
void printStack(Stack<T> &stack);

// Initialize a stack.
template<class T>
void initStack(Stack<T> &stack);

// Delete a stack.
template<class T>
void closeStack(Stack<T> &stack);

// Return number of element in the stack.
template<class T>
int sizeStack(Stack<T> &stack);

// Return true if the stack size is 0, false otherwise.
template<class T>
bool isEmpty(Stack<T> &stack);

// Return a reference to the top element in the stack.
template<class T>
T& topStack(Stack<T> &stack);

// Insert a new element at the top of the stack.
template<class T>
void pushStack(Stack<T> &stack, const T &value);

// Remove the element on top of the stack.
template<class T>
void popStack(Stack<T> &stack);

#endif // End of file StackCPP_T.h