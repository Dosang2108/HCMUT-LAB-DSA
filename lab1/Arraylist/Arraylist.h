#include <bits/stdc++.h>

using namespace std;

template <class T>
class ArrayList {
private:
    T* data;         // Pointer to the array of elements
    int capacity;    // Current capacity of the array
    int count;       // Number of elements in the array
public:
    ArrayList(int initial_capacity = 10) : capacity(initial_capacity), count(0) {
        data = new T[capacity];  // Allocate memory for the array
    }

    ~ArrayList() {
        delete[] data;  // Free the allocated memory
    }

    void ensureCapacity(int cap);  // Ensure enough capacity for new elements
    void add(T e);                 // Add an element to the end of the list
    void add(int index, T e);      // Add an element at a specific index
    int size();                   // Get the current size of the list
    T get(int index);             // Get an element at a specific index
    T removeAt(int index);        // Remove an element at a specific index
    bool removeItem(T item);      // Remove the first occurrence of an item
    void clear();                 // Clear the list

};