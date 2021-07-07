#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode *head) {
            if (!head) return nullptr;
            ListNode *curr = head, *prev = nullptr;
            while (curr && curr->next) {
                bool flag = false;
                while (curr && curr->next && curr->val == curr->next->val) {
                    curr = curr->next;
                    flag = true;
                }
                if (flag) {
                    if (!prev) {
                        head = curr->next;
                    } else {
                        prev->next = curr->next;
                    }
                    curr = curr->next;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    print(head);

    Solution sol;
    print(sol.deleteDuplicates(head));

    return 0;
}

