#include <iostream>
#include <vector>

using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    for (size_t i = 0; i < operations.size(); i++)
    {
        for (int j=operations[i][0];j<=operations[i][1];j++)
        {
            nums[j]+=operations[i][2];
        }
    }
    return nums;
}