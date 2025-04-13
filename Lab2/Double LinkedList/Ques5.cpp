// Problem: Reverse a doubly linked list between two given positions
#include <iostream>
#include <unordered_map>
using namespace std;
// Define the ListNode structure for a doubly linked list
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};

ListNode* reverse(ListNode* head, int a, int b) {
    unordered_map<int ,ListNode* > v;
    ListNode* tmp = head;
    int index = 1;
    int i = b;
    while(tmp){
        if(index >= a && index <= b){
            v[i] = tmp;
            i--;
        }
        else v[index] = tmp;
        tmp = tmp->right;
        index ++;
    }
    head = v[1];
    head->left = NULL;
    tmp = head;
    for(int i = 2; i < index; i++){
        tmp->right = v[i];
        v[i]->left = tmp;
        tmp = v[i];
    }
    tmp->right = NULL;
    return head;
}
