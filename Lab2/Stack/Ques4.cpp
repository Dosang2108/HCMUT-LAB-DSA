#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    stack<char> str; // Initialize the stack

    for (char c : S) {
        // Check if the stack is not empty and the top element is the same as the current character
        if (!str.empty() && str.top() == c) {
            str.pop(); // Remove the top element (adjacent duplicate)
        } else {
            str.push(c); // Add the current character to the stack
        }
    }

    // Build the result string from the stack
    string result = "";
    while (!str.empty()) {
        result = str.top() + result; // Prepend to result
        str.pop();
    }

    return result;
}
