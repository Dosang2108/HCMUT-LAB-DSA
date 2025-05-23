#include <iostream>

using namespace std;
void printff(int n, int step, bool up) {
    cout << n;
    if (n == step && up) {
        return;
    }
    cout << " ";
    if (!up && (n - 5 > 0)) {
        printff(n - 5, step, false);
    }
    else if (!up) {
        printff(n - 5, step, true);
    }
    else {
        printff(n + 5, step, true);
    }
}

void printPattern(int n) {
    printff(n, n, false);
}
