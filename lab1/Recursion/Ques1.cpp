#include <iostream>
using namespace std;

void printff(int i, int n) {
    if (i > n) return;
    cout << i;
    if (i != n) cout << ", ";
    printff(i + 1, n);
}

void printArray(int n) {
    printff(0, n);
}