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
        ListNode* reverseList(ListNode* head) {
            ListNode *prev = nullptr, *next = nullptr, *curr = head;
            while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }

        ListNode* swapPairs(ListNode *head) {
            int count = 2, first_pair = 1;
            ListNode *curr = head, *new_head = nullptr, *last, *last_last, *first = head;

            while (curr) {
                while (count-- && curr) {
                    last = curr;
                    curr = curr->next;
                }
                if (count > 0) break;
                last->next = nullptr;
                if (first_pair) {
                    new_head = reverseList(first);
                    first = new_head;
                    first_pair = 0;
                } else {
                    first = reverseList(first);
                    last_last->next = first;
                }
                while (first) {
                    last_last = first;
                    first = first->next;
                }
                first = curr;
                count = 2;
            }
            return new_head;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    print(head);

    std::cout << "***** SOLUTION *****\n";
    Solution sol;
    print(sol.swapPairs(head));
    return 0;
}

