#include "LinkedList.h"

void LinkedList::partition(int k) {
    Node* less_head = nullptr; // Đầu của nhóm I
    Node* less_last = nullptr; // Cuối của nhóm I
    Node* equal_head = nullptr; // Đầu của nhóm II
    Node* equal_last = nullptr; // Cuối của nhóm II
    Node* greater_head = nullptr; // Đầu của nhóm III
    Node* greater_last = nullptr; // Cuối của nhóm III
    Node* current = head; // Node hiện tại đang xem xét

    while (current != nullptr) {
        Node* next_node = current->next;

        if (current->value < k) {
            // Nếu giá trị của Node nhỏ hơn k, thêm vào nhóm I
            if (!less_head) {
                less_head = new Node(current->value);
                less_last = less_head;
            } else {
                less_last->next = new Node(current->value);
                less_last = less_last->next;
            }
        } else if (current->value == k) {
            // Nếu giá trị của Node bằng k, thêm vào nhóm II
            if (!equal_head) {
                equal_head = new Node(current->value);
                equal_last = equal_head;
            } else {
                equal_last->next = new Node(current->value);
                equal_last = equal_last->next;
            }
        } else {
            // Nếu giá trị của Node lớn hơn k, thêm vào nhóm III
            if (!greater_head) {
                greater_head = new Node(current->value);
                greater_last = greater_head;
            } else {
                greater_last->next = new Node(current->value);
                greater_last = greater_last->next;
            }
        }
        current = next_node;
    }

    // Kết hợp các nhóm lại với nhau
    head = nullptr;
    if (less_head) {
        head = less_head;
        tail = less_last;
    }
    if (equal_head) {
        if (!head) {
            head = equal_head;
        } else {
            tail->next = equal_head;
        }
        tail = equal_last;
    }
    if (greater_head) {
        if (!head) {
            head = greater_head;
        } else {
            tail->next = greater_head;
        }
        tail = greater_last;
    }
    if (tail) {
        tail->next = nullptr;
    }
}