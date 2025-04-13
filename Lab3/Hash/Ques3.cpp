#include "Hash.h"
template<class K, class V>
V XHashMap<K, V>::remove(int key) {
    /*
            An index need to find by using the hash function,
            then find the Entry of this index
                
            Check if the key already exists. If yes, remove the key from the table
            
            If the key doesn't exist, throw out_of_range("Key not found");
        
        */
            int index = hashFunction(key, capacity);
        Entry* entry = table[index];
        Entry* prev = nullptr;
        while (entry != nullptr) {
            if (entry->key == key) {
                V value = entry->value;
                if (prev == nullptr) {
                    table[index] = entry->next; // Remove from head
                } else {
                    prev->next = entry->next; // Remove from middle or end
                }
                delete entry;
                count--;
                return value;
            }
            prev = entry;
            entry = entry->next;
        }
        throw std::out_of_range("Key not found"); 
    }