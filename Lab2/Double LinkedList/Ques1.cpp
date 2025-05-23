#include "DLinkedList.h"
template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e);
    if (tail == nullptr) { // List is empty
        head = tail = newNode;
    } else {
        tail->next = newNode; // Link the last node to the new node
        newNode->previous = tail; // Link the new node back to the last node
        tail = newNode; // Update tail to the new node
    }
    count++; // Increase the count
    
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    Node* newNode = new Node(e);
    if (index == 0) { // Insert at the head
        if (head == nullptr) { // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head; // Link new node to the current head
            head->previous = newNode; // Link current head back to new node
            head = newNode; // Update head to the new node
        }
    } else if (index == count) { // Insert at the tail
        add(e); // Use the existing add method
        return;
    } else { // Insert in the middle
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next; // Traverse to the index
        }
        newNode->previous = current->previous; // Link new node back to the previous node
        newNode->next = current; // Link new node to the current node
        if (current->previous != nullptr) {
            current->previous->next = newNode; // Link the previous node to the new node
        }
        current->previous = newNode; // Link the current node back to the new node
    }
    count++; // Increase the count
    
    
    
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}