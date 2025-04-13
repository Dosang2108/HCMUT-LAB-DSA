#ifndef Hash_h
#define Hash_h
#include <iostream>
#include <cmath>
#include <stdexcept> // for std::out_of_range
#include <string>
#include <sstream>


using namespace std;
int hashFunction(int key, int capacity) {
    return key % capacity;
}

template<class K, class V>
class XHashMap {
public:
    class Entry {
    public:    
        K key;
        V value;  
        Entry* next; 
        
        Entry(K key, V value, Entry* next = 0) {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };

private:
    Entry** table; // hash table
    int capacity; // size for the hash table
    int count;   

public:
    // Constructor
    XHashMap() {
        this->capacity = 10;
        this->count = 0;
        table = new Entry*[capacity];
        //reset table to 0
        for (int i = 0; i < capacity; i++) {
            table[i] = 0;  
        }
    }

    ~XHashMap(){ // Destructor
        //Remove all entries in the current map
        for(int idx=0; idx < this->capacity; idx++){
            Entry* entry = this->table[idx];
            while(entry != 0){
                Entry * next = entry->next;
                delete entry;
                entry = next;
            }
        }
        //Remove table
        delete []table;
    } 
        
    // YOUR ANSWER    

    // print table method (for testing)
    void printTable() const {

        cout << "------------The hash table is shown below------------\n";
        for (int i = 0; i < capacity; i++) {
            Entry* entry = table[i];
            cout << "Index " << i << ": ";
            while (entry != 0) {
                cout << "(" << entry->key << ", " << entry->value << ") ";
                entry = entry->next;
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
        
    }
    void put(int key, int value);
    void  ensureLoadFactor(int current_size);
    void rehash(int newCapacity);

    V& get(K key); 
    bool containsKey(int key);
    V remove(int key)

    
};


#endif // Hash_h