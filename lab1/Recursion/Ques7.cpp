#include <iostream>
#include <string>

using namespace std;


void printHailstone(int number) {
    cout << number;
    if (number == 1) return;
    if (number % 2 == 0) {
        cout <<" ";
        printHailstone(number / 2);
    } else {
        cout <<" ";
        printHailstone(number * 3 + 1);
    }
}