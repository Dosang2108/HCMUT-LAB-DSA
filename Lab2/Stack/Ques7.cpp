#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
    Problem: Given an array of stock prices, find the span of stock prices for each day. 
    The span of stock price on a given day is defined as the maximum number of consecutive days before 
    the given day where the price was less than or equal to the price on that day.

*/
// For example, if the prices are [100, 80, 60, 70, 60, 75, 85], the spans would be [1, 1, 1, 2, 1, 4, 6].

vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> result = {1};
    int size = ns.size();
    
    for (int i = 1; i < size; i++) {
        if (ns[i] <= ns[i-1]) result.push_back(1);
        else {
            int count = 1;
            for (int j = i - 1; j >= 0 && ns[j] < ns[i]; j--) count++;
            result.push_back(count);
        }
    }
    return result;
}