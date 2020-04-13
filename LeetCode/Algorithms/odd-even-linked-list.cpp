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
        ListNode* oddEvenList(ListNode *head) {
            if (!head || !head->next) return head;
            int counter = 1;
            ListNode *curr = head, *prev = nullptr;
            ListNode dummy_o(0), dummy_e(0);
            ListNode *tail_o = &dummy_o, *tail_e = &dummy_e;
            while (curr) {
                if (counter % 2) {
                    tail_o->next = curr;
                    tail_o = tail_o->next;
                } else {
                    tail_e->next = curr;
                    tail_e = tail_e->next;
                }
                counter++;
                curr = curr->next;
            }
            tail_o->next = nullptr;
            tail_e->next = nullptr;
            tail_o->next = dummy_e.next;
            return dummy_o.next;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);
    print(head);

    Solution sol;
    print(sol.oddEvenList(head));

    return 0;
}

