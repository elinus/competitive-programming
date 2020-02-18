#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    public:
        int getListLength(ListNode *head) {
            ListNode *curr = head;
            int length = 0;
            while (curr) {
                length++;
                curr = curr->next;
            }
            return length;
        }

        ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* intr_node = nullptr;
            int length_a = getListLength(headA);
            int length_b = getListLength(headB);
            int diff = length_a - length_b;
            ListNode *curr_a = headA, *curr_b = headB;
            if (diff > 0) {
                while(diff--) {
                    curr_a = curr_a->next;
                }
            } else {
                diff = diff * (-1);
                while(diff--) {
                    curr_b = curr_b->next;
                }
            }
            while (curr_a != nullptr && curr_b != nullptr) {
                if (curr_a == curr_b) return curr_a;
                curr_a = curr_a->next;
                curr_b = curr_b->next;
            }
            return intr_node;
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
    
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    print(head1);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = head1->next->next/*new ListNode(3)*/;
//    head2->next->next->next = new ListNode(4);
//    head2->next->next->next->next = new ListNode(5);
    print(head2);

    Solution sol;
    std::cout << sol.getIntersectionNode(head1, head2)->val << "\n";

    return 0;
}

