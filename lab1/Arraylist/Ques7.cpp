#include <iostream>
#include <vector>

using namespace std;

int longestSublist(vector<string>& words) {
    if (words.empty()) return 0;

    int maxLen = 1, currentLen = 1;
    char currentChar = words[0][0];

    for (int i = 1; i < words.size(); i++) {
        if (words[i][0] == currentChar) {
            currentLen++;
        } else {
            maxLen = max(maxLen, currentLen);
            currentLen = 1;
            currentChar = words[i][0];
        }
    }

    return max(maxLen, currentLen);
}