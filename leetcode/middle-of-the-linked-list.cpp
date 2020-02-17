#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    public:
        ListNode* middleNode(ListNode* head) {
            int list_length = 0;
            ListNode* curr = head;
            while (curr) {
                list_length++;
                curr = curr->next;
            }

            curr = head;
            list_length /= 2;
            while (list_length--) {
                curr = curr->next;
            }
            return curr;
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
    head->next->next->next->next->next = new ListNode(6);
    print(head);

    Solution sol;
    print(sol.middleNode(head));

    return 0;
}

