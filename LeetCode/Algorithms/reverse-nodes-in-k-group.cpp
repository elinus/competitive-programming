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

        int getListLength(ListNode *head) {
            int length = 0;
            ListNode *curr = head;
            while (curr) {
                curr = curr->next;
                length++;
            }
            return length;
        }

        ListNode* reverseKGroup(ListNode *head, int k) {
            if (k <= 0 || k > getListLength(head)) return head;
            
            int count = k, first_pair = 1;
            ListNode *curr = head, *new_head = nullptr, *last, *first = head, *prev_ = nullptr, *next_ = nullptr;
            
            while (curr) {
                first = curr;
                last = nullptr;
                while (curr && count--) {
                    last = curr;
                    curr = curr->next;
                }
                last->next = nullptr;
                if (prev_ != nullptr && next_ != nullptr) {
                    if (count > 0) { 
                        prev_->next = first;
                        break;
                    }
                    prev_->next = last;
                }

                prev_ = first;
                next_ = last;

                if (first_pair) {
                    new_head = last;
                    first_pair = 0;
                }
                first = reverseList(first);
                count = k;
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
    print(sol.reverseKGroup(head, 3));
    return 0;
}

