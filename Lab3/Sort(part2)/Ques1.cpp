#include "Sorting.h"

template <class T>
static T* Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T p = start[0];    // pivot
        int i = 0;
        int j = end - start;
        do
        {
            do
            {
                i++;
            } while (start[i] <= p);
            do
            {
                j--;
            } while (start[j]>p);
            swap(start[i], start[j]);
        } while (i<j);
        swap(start[i], start[j]);
        swap(start[0], start[j]);
        return start + j;
    
}
template <class T>
static void QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    if(start < end){
        T* pivot = Partition(start, end);
        cout  << pivot -start << " ";
        QuickSort(start, pivot);
        QuickSort(pivot + 1, end);
    }
    
}