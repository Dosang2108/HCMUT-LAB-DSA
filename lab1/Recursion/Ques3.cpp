#include<iostream>

using namespace std;

int findMax(int* arr, int length) {
    if (length == 1) return *arr;
    int mx = findMax(arr + 1, length - 1);
    return (*arr > mx) ? *arr : mx;
}