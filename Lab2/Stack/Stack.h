#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) ;
    T pop() ;
    T top() ;
    void push(T item) ; // Push new element into the top of the stack
    T pop() ; // Remove an element on top of the stack
    T top() ; // Get value of the element on top of the stack
    bool empty() ; // Determine if the stack is empty
    int size() ; // Get the size of the stack
    void clear() ;
    void printStack() const { // Print the stack elements
        /* Print the stack elements */
        list.printList(); // Use the printList method from DLinkedList
    };
};

#endif