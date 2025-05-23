#include <iostream>
#include <vector>

using namespace std;
int baseballScore(string ops) {
    /*TODO*/
        vector<int> record;
    
        for (char op : ops) {
            if (isdigit(op)) {
                // If the character is a digit, record its integer value
                record.push_back(op - '0');
            } else if (op == '+') {
                // Add the sum of the previous two scores
                int last = record.back();
                int secondLast = record[record.size() - 2];
                record.push_back(last + secondLast);
            } else if (op == 'D') {
                // Add double the last score
                int last = record.back();
                record.push_back(last * 2);
            } else if (op == 'C') {
                // Invalidate the last score
                record.pop_back();
            }
        }
    
        // Return the sum of all the scores
        int totalScore = 0;
        for (int score : record) {
            totalScore += score;
        }
        
        return totalScore;
    }