#include "SLinkedList.h"

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
     if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    return current->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count) {
        throw std::out_of_range("Index out of range");
    }
    
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    
    current->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (this->count==0) return true;
    return false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
     Node* current = head;
    for (int i = 0; i < count; i++) {
        if (current->data == item) {
            return i;
        }
        current = current->next;
    }
    return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
     return indexOf(item) != -1;
}
