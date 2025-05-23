#include <iostream>
#include <vector>
#include <deque> // For deque

using namespace std;

int sumOfMaxSubarray(vector<int>& nums, int k) {
    // STUDENT ANSWER
    int n = nums.size();
    if (n == 0 || k == 0 || k > n) return 0; // Edge case handling
    int result = 0;
    deque<int> dq; // This will store indices of the array elements
    for (int i = 0; i < n; ++i) {
        // Remove elements not in the sliding window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // Remove smaller elements in k range as they are useless
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        // Add current element at the back of the deque
        dq.push_back(i);
        // The first k elements will be added to result after filling the first window
        if (i >= k - 1) {
            result += nums[dq.front()]; // Add the maximum for this window
        }
    }

    return result;
}