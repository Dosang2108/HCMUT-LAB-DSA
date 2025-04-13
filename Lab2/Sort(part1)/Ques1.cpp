#include "SLinkedList.h"
template <class T>
void SLinkedList<T>::bubbleSort()
{
  if (this->count == 0 || this->count == 1){
       return;
  }
    Node* unsorted = this->head;
    Node* sorted = this->tail->next;
    Node* sentinel = sorted;
    bool isSwapped = true;
    while (isSwapped) {
        sentinel = sorted;
        isSwapped = false;
        unsorted = this->head;
        while (unsorted->next != sorted) {
            if (unsorted->data > unsorted->next->data) {
                T temp = unsorted->data;
                unsorted->data = unsorted->next->data;
                unsorted->next->data = temp;
                isSwapped = true;
            }
            unsorted = unsorted->next;
        }
        sorted = this->head;
        while (sorted->next != sentinel){
            sorted = sorted->next;
        }
            if (isSwapped){
                this->printList();
            }
    }
}