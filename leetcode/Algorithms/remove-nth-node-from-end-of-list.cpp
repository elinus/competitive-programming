#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            int list_len = 0;
            ListNode *curr = head, *prev = nullptr;
            while (curr) {
                list_len++;
                curr = curr->next;
            }
            if (list_len <= 0 || n > list_len || n <= 0) {
                return head;
            }
            curr = head;
            int diff = list_len - n + 1;
            while (--diff) {
                prev = curr;
                curr = curr->next;
            }
            if (prev) {
                prev->next = curr->next;
            } else {
                head = head->next;
            }
            return head;
        }
};

int main (int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *curr = sol.removeNthFromEnd(head, 5);

    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";

    return 0;
}

