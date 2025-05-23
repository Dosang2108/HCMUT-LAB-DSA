#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void interleaveQueue(queue<int>& q){
    int n = q.size();
    // Create a stack to reverse the first half of the queue
    stack<int> s;   
    // Step 1: Push the first half of the queue into the stack
    for (int i = 0; i < n / 2; ++i) {
        s.push(q.front());
        q.pop();
    }
    // Step 2: Enqueue the stack contents back to the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    // Step 3: Dequeue the first half and enqueue it to the back of the queue
    for (int i = 0; i < n / 2; ++i) {
        q.push(q.front());
        q.pop();
    }
    // Step 4: Again, push the first half to the stack
    for (int i = 0; i < n / 2; ++i) {
        s.push(q.front());
        q.pop();
    }
    // Step 5: Interleave the elements from the stack and the queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}