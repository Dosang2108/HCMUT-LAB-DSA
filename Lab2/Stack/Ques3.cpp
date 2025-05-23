#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreater(vector<int>& arr){
    int n = arr.size();
    vector<int> result(n, -1); // Initialize result array with -1
    stack<int> s; // Stack to keep track of indices

    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack until we find a greater element
        while (!s.empty() && arr[i] >= arr[s.top()]) {
            s.pop();
        }

        // If stack is not empty, the top element is the next greater
        if (!s.empty()) {
            result[i] = arr[s.top()];
        }

        // Push current index onto the stack
        s.push(i);
    }

    return result;
}