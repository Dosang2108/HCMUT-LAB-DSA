#include "Arraylist.h"

template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if (index<0 || index> this->capacity)
       throw std::out_of_range("index is out of range");
    
    T value = this->data[index];
    
    for (int i=index;i<this->count-1;i++)
    {
        this->data[i]=this->data[i+1];
    }   
    this->count--;
    return value;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
    for (int i=0;i<this->count;i++)
    {
        if (this->data[i]==item) 
        {
             removeAt(i);
            return true;
        }
    }
    return false;
    
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if (this->data != nullptr) {
        delete[] this->data;  // Free memory if not null
    }
    
    this->data = new T[5];
    this->count=0;
    this-> capacity=5;
    
}