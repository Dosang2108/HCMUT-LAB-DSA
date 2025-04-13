#include "Sorting.h"
template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int size = end - start;
    for (int i = 0; i < size - 1; ++i) {
        int min = start[i];
        int index = i;
        for (int j = i + 1; j < size; ++j) {
            if (start[j] < min)  {
                min = start[j];
                index = j;
            }
        }
        int temp = start[i];
        start[i] = start[index];
        start[index] = temp;
        Sorting<T>::printArray(start, end);
    }
}