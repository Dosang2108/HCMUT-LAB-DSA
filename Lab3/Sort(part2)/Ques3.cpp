#include <iostream>
#include <cmath>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};
ListNode* mergeLists(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->val <= b->val) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != nullptr) {
        tail->next = a;
    }
    if (b != nullptr) {
        tail->next = b;
    }
    return dummy.next;
}

ListNode* findMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to sort a linked list using merge sort
ListNode* mergeSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode* mid = findMiddle(head);
    ListNode* secondHalf = mid->next;
    mid->next = nullptr; 
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(secondHalf);
    return mergeLists(left, right);
}