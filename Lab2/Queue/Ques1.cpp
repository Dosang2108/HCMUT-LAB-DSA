#include "Queue.h"
template<class T>
void push(T item) {
    // TODO: Push new element into the end of the queue
    list.add(item);
}
template<class T>
T pop() {
    // TODO: Remove an element in the head of the queue
    return list.removeAt(0);
}
template<class T>
T top() {
    // TODO: Get value of the element in the head of the queue
    return list.get(0);
}
template<class T>
bool empty() {
    // TODO: Determine if the queue is empty
    return list.empty();
}
template<class T>
int size() {
    // TODO: Get the size of the queue
    return list.size();
        
}
template<class T>
void clear() {
    // TODO: Clear all elements of the queue
    list.clear();
}