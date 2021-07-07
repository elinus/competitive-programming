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
    private:
        ListNode* reverse(ListNode *head) {
            ListNode *curr = head, *prev = nullptr, *next = nullptr;
            while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
            l1 = reverse(l1);
            l2 = reverse(l2);
            int carry = 0;
            ListNode dummy(0);
            ListNode *tail = &dummy;
            while (l1 && l2) {
                int sum = l1->val + l2->val + carry;
                if (sum >= 10) {
                    carry = 1;
                    sum = sum % 10;
                } else {
                    carry = 0;
                }
                tail->next = new ListNode(sum);
                tail = tail->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            while (l1) {
                int sum = l1->val + carry;
                if (sum >= 10) {
                    carry = 1;
                    sum = sum % 10;
                } else {
                    carry = 0;
                }
                tail->next = new ListNode(sum);
                tail = tail->next;
                l1 = l1->next;
            }
            while (l2) {
                int sum = l2->val + carry;
                if (sum >= 10) {
                    carry = 1;
                    sum = sum % 10;
                } else {
                    carry = 0;
                }
                tail->next = new ListNode(sum);
                tail = tail->next;
                l2 = l2->next;
            }
            while (carry) {
                tail->next = new ListNode(carry);
                tail = tail->next;
                carry = 0;
            }
            return reverse(dummy.next);
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head1 = new ListNode(7);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(3);
    print(head1);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    print(head2);

    Solution sol;
    print(sol.addTwoNumbers(head1, head2));

    return 0;
}

