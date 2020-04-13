#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    ListNode* reverse(ListNode *head) {
        ListNode *curr = head, *prev = nullptr, *next = nullptr; 
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p1 = nullptr, *curr = head, *p2 = nullptr, *start = nullptr;
        int diff = n - m + 1;
        while (--m) {
            p1 = curr;
            curr = curr->next;
        }
        start = curr;
        while (diff--) {
            p2 = curr;
            curr = curr->next;
        }
        p2->next = nullptr;
        if (p1)
            p1->next = reverse(start);
        else 
            head = reverse(start);
        start->next = curr;
        return head;
    }
};

void print(ListNode* head) {
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

int main (int argc, char *argv[]) {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    /* Code */

    return 0;
}

