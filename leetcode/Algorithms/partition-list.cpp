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
        ListNode* partition(ListNode* head, int x) {
            if (!head || !head->next) return head;
            ListNode dummy_0(0), dummy_1(0);
            ListNode *tail_0 = &dummy_0, *tail_1 = &dummy_1, *curr = head;
            while (curr) {
                if (curr->val < x) {
                    tail_0->next = curr;
                    tail_0 = tail_0->next;

                } else {
                    tail_1->next = curr;
                    tail_1 = tail_1->next;
                }
                curr = curr->next;
            }

            if (tail_0) tail_0->next = nullptr;
            if (tail_1) tail_1->next = nullptr;
            if (dummy_0.next) {
                head = dummy_0.next;
                tail_0->next = dummy_1.next;
            } else {
                head = dummy_1.next;
            }

            return head;
        }
};

int main (int argc, char *argv[]) {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    print(head);

    Solution sol;
    print(sol.partition(head, 3));

    return 0;
}

