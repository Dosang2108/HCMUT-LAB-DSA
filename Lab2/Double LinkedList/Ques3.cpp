#include "DLinkedList.h"
template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next; // Traverse to the index
    }

    T data = current->data; // Store data to return
    if (current->previous != nullptr) {
        current->previous->next = current->next; // Link previous to next
    } else {
        head = current->next; // Update head if removing the first element
    }
    
    if (current->next != nullptr) {
        current->next->previous = current->previous; // Link next to previous
    } else {
        tail = current->previous; // Update tail if removing the last element
    }
    
    delete current; // Free the removed node
    count--; // Decrease the count
    return data; // Return the removed value
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    int index = indexOf(item); // Find the index of the item
    if (index != -1) {
        removeAt(index); // Remove item at found index
        return true; // Return true as item was removed
    }
    return false; // Return false as item was not found
    
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp; // Free each node
    }
    tail = nullptr; // Set tail to nullptr
    count = 0; // Reset count
}