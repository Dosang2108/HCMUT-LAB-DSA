#include"SLinkedList.h"

template <class T>
void SLinkedList<T>::add(const T& e) {
    if (head == NULL)   {head = tail = new Node(e,NULL); count++; return;}
    Node* tmp = new Node(e,NULL);
    tail -> next = tmp;
    tail = tail -> next;
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if(index > this->count || index < 0){
        return;
    }
    if(index == count && this-> count != 0){
        add(e);
        return;
    }
    Node* pNew = new Node (e, NULL);
    if(this->count == 0){
        this->head = this->tail = pNew;
    }else if(index == 0) {
        pNew->next = this->head;
        this->head = pNew;
    }else{
        Node* current = this->head;
        for(int i = 0; i < index -1; i++){
            current = current->next;
        }
        pNew->next = current->next;
        current-> next = pNew;
    }
    ++this->count;
}

template<class T>
int SLinkedList<T>::size() {
    return count;
}
