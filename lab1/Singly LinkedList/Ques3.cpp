#include "SLinkedList.h"

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index is out of range");
    }

    Node* prev = nullptr;
    Node* curr = head;
    
    for (int i = 0; i < index; i++) {
        prev = curr;
        curr = curr->next;
    }

    T removedData = curr->data;

    if (prev == nullptr) { // Removing the head
        head = head->next;
    } else {
        prev->next = curr->next;
    }

    if (curr == tail) { // If the last node is removed, update the tail
        tail = prev;
    }

    delete curr;
    count--;

    return removedData;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
     Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->data == item) {
            if (prev == nullptr) { // Removing the head
                head = head->next;
            } else {
                prev->next = curr->next;
            }

            if (curr == tail) { // If the last node is removed, update the tail
                tail = prev;
            }

            delete curr;
            count--;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }

    return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;
    
}
