#include <iostream>
#include<cmath>

int change(char *str, int n, int cur) {
    if (cur == n) return 0;
    return (str[cur] - '0') * pow(10, n - cur - 1) + change(str, n, cur + 1);
}

int myArrayToInt(char *str, int n) {
    return change(str, n, 0);
}