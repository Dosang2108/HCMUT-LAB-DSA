#include "Hash.h"

template<class K, class V>
V& XHashMap<K, V>::get(K key) {
    int index = hashFunction(key, capacity);
    Entry* entry = table[index];

    while (entry != nullptr) {
        if (entry->key == key) {
            return entry->value;  // Key found, return its value
        }
        entry = entry->next;
    }

    throw std::out_of_range("Key not found");
}