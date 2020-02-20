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
    public:
        bool hasCycle(ListNode *head) {
            ListNode *slow = head, *fast = head;
            while (slow && fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) return true;
            }
            return false;
        }
};

int main (int argc, char *argv[]) {

    ListNode *head = new ListNode(1);
//    head->next = new ListNode(2);
//    head->next->next = head;

    Solution sol;
    std::cout << sol.hasCycle(head) << "\n";

    return 0;
}

