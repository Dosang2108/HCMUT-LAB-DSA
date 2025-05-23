#include "Arraylist.h"

template<class T>
void ArrayList<T>::ensureCapacity(int cap) {
    if (cap > this->capacity) {
        int new_capacity = static_cast<int>(this->capacity * 1.5);
        T* new_data = new T[new_capacity];
        
        // Copy old data to new array
        for (int i = 0; i < this->count; i++) {
            new_data[i] = this->data[i];
        }
        
        delete[] this->data;  // Free the old array
        this->data = new_data;
        this->capacity = new_capacity;
    }
}


template <class T>
void ArrayList<T>::add(T e) {
    ensureCapacity(this->count + 1);  // Ensure there's enough space
    this->data[this->count++] = e;    // Insert the element and increase count
}


template<class T>
void ArrayList<T>::add(int index, T e) {
    if (index < 0 || index > this->count) {
        throw std::out_of_range("Index is out of range");
    }
    
    ensureCapacity(this->count + 1);  // Ensure enough capacity
    
    // Shift elements to the right
    for (int i = this->count; i > index; i--) {
        this->data[i] = this->data[i - 1];
    }
    
    // Insert the new element
    this->data[index] = e;
    this->count++;
}



template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return this->count;
}