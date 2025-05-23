#include <iostream>
#include <vector>

using namespace std;

int equalSumIndex(vector<int>& nums) {
    int rsum = 0;
    for (int i = 1; i < nums.size(); i++) {
        rsum += nums[i];
    }
    
    int lsum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (lsum == rsum) return i;
        if (i < nums.size() - 1) {
            lsum += nums[i];
            rsum -= nums[i + 1];
        }
    }
    
    return -1;
}