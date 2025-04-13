#ifndef Queue_H
#define Queue_H

template<class T>
class Queue {
protected:
    DLinkedList<T> list; // List to store elements of the queue

public:
    Queue() {} // Constructor

    void push(T item); // Push new element into the end of the queue
    T pop(); // Remove an element in the head of the queue
    T top(); // Get value of the element in the head of the queue
    bool empty(); // Determine if the queue is empty
    int size(); // Get the size of the queue
    void clear(); // Clear all elements of the queue

    void printQueue() const { // Print the queue elements
        /* Print the queue elements */
        list.printList(); // Use the printList method from DLinkedList
    };
};

#endif // Queue_H