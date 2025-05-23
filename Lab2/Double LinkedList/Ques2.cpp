#include "DLinkedList.h"
template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next; // Traverse to the index
    }
    return current->data; // Return the data of the found node
    
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
     if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next; // Traverse to the index
    }
    current->data = e; // Update the data
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count==0;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
     Node* current = head;
    for (int i = 0; i < count; ++i) {
        if (current->data == item) {
            return i; // Return the index if item is found
        }
        current = current->next; // Move to the next node
    }
    return -1; // Return -1 if item is not found
    
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return indexOf(item)!=-1;
    
}