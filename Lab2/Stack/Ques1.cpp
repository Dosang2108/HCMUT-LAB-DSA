#include "Stack.h"
template<class T>
void push(T item) {
    // TODO: Push new element into the top of the stack
    list.add(item);
}
template<class T>
T pop() {
    // TODO: Remove an element on top of the stack
        return list.removeAt(list.size()-1);
}
template<class T>
T top() {
    // TODO: Get value of the element on top of the stack
        return list.get(list.size()-1);
}
template<class T>
bool empty() {
    // TODO: Determine if the stack is empty
    return list.empty();
        
}
template<class T>
int size() {
    // TODO: Get the size of the stack
    return list.size();
        
}
template<class T>
void clear() {
    // TODO: Clear all elements of the stack
    list.clear();
}
