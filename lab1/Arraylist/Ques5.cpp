#include <iostream>
#include <vector>

using namespace std;

int buyCar(int* nums, int length, int k) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
int count = 0;
    for (int i = 0; i < length; i++) {
        if (k >= nums[i]) {
            k -= nums[i];
            count++;
        } else {
            break;
        }
    }

    return count;
    
}