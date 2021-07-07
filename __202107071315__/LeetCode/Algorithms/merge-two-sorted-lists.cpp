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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if (!l1) return l2;
            if (!l2) return l1;
            ListNode dummy(0);
            ListNode *tail = &dummy;
            ListNode *curr1 = l1, *curr2 = l2;
            
            while (curr1 != nullptr && curr2 != nullptr) {
                if (curr1->val <= curr2->val) {
                    tail->next = curr1;
                    curr1 = curr1->next;
                } else {
                    tail->next = curr2;
                    curr2 = curr2->next;
                }
                tail = tail->next;
            }
            while (curr1 != nullptr) {
                tail->next = curr1;
                curr1 = curr1->next;
                tail = tail->next;
            }
            while (curr2 != nullptr) {
                tail->next = curr2;
                curr2 = curr2->next;
                tail = tail->next;
            }
            return dummy.next;
        }    
};

int main (int argc, char *argv[]) {

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    print(head1);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    print(head2);

    Solution sol;
    print(sol.mergeTwoLists(head1, head2));

    return 0;
}

