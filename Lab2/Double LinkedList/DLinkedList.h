#ifndef DLinkedList_H
#define DLinkedList_H
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;
template <class T>
class DLinkedList {
private:
    struct Node {
        T data; // Data of the node
        Node* next; // Pointer to the next node
        Node* previous; // Pointer to the previous node

        Node(const T& d) : data(d), next(nullptr), previous(nullptr) {} // Constructor
    };

    Node* head; // Pointer to the head of the list
    Node* tail; // Pointer to the tail of the list
    int count; // Number of elements in the list
public:
    DLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor
    ~DLinkedList() { clear(); } // Destructor

    void add(const T& e); // Add element to the end of the list
    void add(int index, const T& e); // Add element at given index
    T removeAt(int index); // Remove element at given index and return it
    bool removeItem(const T& item); // Remove first appearance of item in list
    void clear(); // Clear the list

    T get(int index); // Get element at given index
    void set(int index, const T& e); // Set element at given index
    bool empty(); // Check if the list is empty
    int size(); // Get the size of the list
    int indexOf(const T& item); // Get the first index of item in the list
    bool contains(const T& item); // Check if item is in the list
    void printList() const{ // Print the list elements
        /* Print the list elements */
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next; // Move to the next node
        }
        cout << endl; // New line after printing all elements
    }; 
};



#endif // DLinkedList_H