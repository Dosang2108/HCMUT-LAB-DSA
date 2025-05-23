#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long nthNiceNumber(int n) {
    queue<long long> q; // Queue to hold nice numbers
    q.push(2); // Start with the first nice number
    q.push(5); // Add the second nice number
    long long currentNiceNumber = 0;
    // We need to generate n nice numbers
    for (int i = 0; i < n; ++i) {
        currentNiceNumber = q.front(); // Get the front of the queue
        q.pop(); // Remove the front number from the queue
        // Generate the next nice numbers
        q.push(currentNiceNumber * 10 + 2); // Append 2
        q.push(currentNiceNumber * 10 + 5); // Append 5
    }
    return currentNiceNumber;
}