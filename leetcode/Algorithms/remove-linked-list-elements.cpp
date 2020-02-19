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
        ListNode* removeElements(ListNode* head, int val) {
            if (!head) return head;
            
            ListNode *curr = head, *prev = nullptr;
            
            while (curr && curr->val == val) curr = curr->next;
		head = curr;
            while (curr) {
                prev = curr;
                if (curr->next && curr->next->val == val) {
                    if (curr->next->next) curr->next = curr->next->next;
                    else curr->next = nullptr;
                } else curr = curr->next;
            }
            return head;
        }
};

int main (int argc, char *argv[]) {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);
    print(head);

    Solution sol;
    print(sol.removeElements(head, 6));

    return 0;
}

