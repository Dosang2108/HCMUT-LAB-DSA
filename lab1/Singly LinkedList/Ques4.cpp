#include<iostream>
#include<string>

class LLNode{
    public:
        int val;
        LLNode* next;
        LLNode(){
            val = 0;
            next = NULL;
        };
        LLNode(int val, LLNode* next){
            this->val = val;
            this->next = next;
        };
        LLNode(int val){
            this->val = val;
            this->next = NULL;
        };
        // TODO
        // Reverse the linked list
        // For example, if the linked list is 1->2->3->4->5, the reversed linked list will be 5->4->3->2->1.
        LLNode* reverseLinkedList(LLNode* head) {
            LLNode* cur = head;
            LLNode* prev = NULL;
            LLNode* nxt = NULL;
            while (cur != NULL){
                nxt = cur -> next;
                cur -> next = prev;
                prev = cur;
                cur = nxt;
            }
            head = prev;
            return head;
        }   
        // TODO
        // Add two linked lists 
        // The digits are stored in reverse order and each of their nodes contain a single digit.
        // Add the two numbers and return it as a linked list.
        // For example, (2 -> 4 -> 3) + (5 -> 6 -> 4) = (7 -> 0 -> 8)      
        LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
            // STUDENT ANSWER
                LLNode* dummyHead = new LLNode(0);  
            LLNode* curr = dummyHead; 
            int carry = 0;
            int total = 0;
            while (l0 || l1 || carry) {
                total = carry;
                if (l0) {
                    total += l0->val;
                    l0 = l0->next;
                }
                if (l1) {
                    total += l1->val;
                    l1 = l1->next;
                }
        
                carry = total / 10;  
                curr->next = new LLNode(total % 10); 
                curr = curr->next;
            }
        
            return dummyHead->next; 
        }
        // TODO
        // Rotate the linked list by k positions
        // For example, if the linked list is 1->2->3->4->5 and k = 2, the rotated linked list will be 4->5->1->2->3.
        LLNode* rotateLinkedList(LLNode* head, int k) {
            if (head == nullptr || k <= 0) {
                 return head;
             }
             int length = 1;
             LLNode* tail = head;
             while (tail->next != nullptr) {
                 tail = tail->next;
                 length++;
             }
             k = k % length;
             if (k == 0) {
                 return head; 
             }
             int new_head_position = length - k;
             LLNode* new_tail = head;
             for (int i = 1; i < new_head_position; i++) {
                 new_tail = new_tail->next;
             }
             LLNode* new_head = new_tail->next;
             new_tail->next = nullptr;
             tail->next = head;
         
             return new_head;
         }
};