#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool consecutiveOnes(vector<int>& nums) {
    int start = -1, end = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (start == -1) start = i;
            end = i;
        }
    }

    if (start == -1) return true;

    for (int i = start; i <= end; i++) {
        if (nums[i] != 1) return false;
    }

    return true;
}