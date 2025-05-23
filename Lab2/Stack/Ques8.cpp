#include <iostream>
#include <stack>
#include <string>
#include <cstdlib> // For exit function

using namespace std;

int performOperation(char operation, int operand1, int operand2) {
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;
    else exit(1);
}

bool isValidOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

bool isValidNumber(char ch) {
    return (ch >= '0' && ch <= '9');
}

int evaluatePostfix(string expr){
    /*TODO*/
     stack<int> s;
    for (size_t i = 0; i < expr.length(); i++) {
        if (expr[i] == ' ') 
            continue;
        else if (isValidOperator(expr[i])) {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            s.push(performOperation(expr[i], operand1, operand2));
        } else if (isValidNumber(expr[i])) {
            int operand = 0;
            // Parse the whole number
            while (i < expr.length() && isValidNumber(expr[i])) {
                operand = (operand * 10) + (expr[i] - '0');
                i++;
            }
            i--;  // Decrement to account for the extra increment in the while loop
            s.push(operand);
        }
    }
    return s.top();  // The result is the only item left in the stack

}