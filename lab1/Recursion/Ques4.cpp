#include<iostream>
#include<string>

using namespace std;


size_t idx = 0;

bool check(string s1, string s2) {
    if (idx == s1.length()) return true;
    if (s1[idx] != s2[idx]) return false;
    idx++;
    return check(s1, s2);
}

string removeSpaces(const string& str, size_t index = 0) {
    if (index == str.length()) return "";
    char currentChar = str[index];
    string rest = removeSpaces(str, index + 1);
    return (currentChar != ' ') ? currentChar + rest : rest;
}

bool isPalindrome(string str) {
    idx = 0;
    string str0 = removeSpaces(str);
    string rev(str0.rbegin(), str0.rend());
    return check(str0, rev);
}