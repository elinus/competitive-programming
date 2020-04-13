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
        ListNode* detectCycle(ListNode *head) {
            if (!head || !head->next) return nullptr;
            ListNode *slow = head, *fast = head;
            while (slow && fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) break;
            }
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
            return nullptr;
        }
};

int main (int argc, char *argv[]) {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = head;
//    head->next->next = new ListNode(0);
//    head->next->next->next = new ListNode(-4);
//    head->next->next->next->next = head->next;

    Solution sol;
    if (sol.detectCycle(head)) {
        std::cout << sol.hasCycle(head)->val << "\n";
    } else {
        std::cout << "nullptr\n";
    }

    return 0;
}

