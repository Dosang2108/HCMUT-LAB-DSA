#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValidParentheses (string s){
    /*TODO*/
     stack<char> st; // Initialize the stack

    for (char c : s) {
        // If it's an opening bracket, push onto the stack
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            // If it's a closing bracket
            if (st.empty()) {
                return false; // No matching opening bracket
            }
            // Check for matching opening bracket
            if ((c == ')' && st.top() != '(') || 
                (c == ']' && st.top() != '[') || 
                (c == '}' && st.top() != '{')) {
                return false; // Mismatched brackets
            }
            st.pop(); // Match found, pop the opening bracket
        }
    }

    // If the stack is empty, all brackets matched correctly
    return st.empty();
}
