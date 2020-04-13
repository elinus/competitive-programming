#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

void print(ListNode* head) {
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}


class Solution {
    void sortedInsert(ListNode **head, ListNode *node) {
        if (*head == nullptr || (*head)->val >= node->val) {
            node->next = *head;
            *head = node;
        } else {
            ListNode *curr = *head;
            while (curr->next && curr->next->val < node->val) {
                curr = curr->next;
            }
            node->next = curr->next;
            curr->next = node;
        }
    }
    public:
        ListNode* insertionSortList(ListNode *head) {
            ListNode *sorted = nullptr, *curr = head, *next = nullptr;
            while (curr) {
                next = curr->next;
                sortedInsert(&sorted, curr);
                curr = next;
            }
            return sorted;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    //head->next->next->next->next = new ListNode(1);
    print(head);

    Solution sol;
    print(sol.insertionSortList(head));

    return 0;
}

