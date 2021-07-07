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
        int getListLength(ListNode *head) {
            ListNode *curr = head;
            int length = 0;
            while (curr) {
                length++;
                curr = curr->next;
            }
            return length;
        }

        ListNode* middleNode(ListNode* head) {
            int list_length = getListLength(head);
            ListNode *curr = head;
            list_length /= 2;
            while (list_length--) {
                curr = curr->next;
            }
            return curr;
        }


        ListNode* reverseList(ListNode* head) {
            ListNode *prev = nullptr, *curr = head, *next = nullptr;
            while (curr) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            return prev;
        }

        bool isPalindrome(ListNode *head) {
            if (!head) return true;
            int length = getListLength(head);
            if (length == 1) return true;
            ListNode *mid = middleNode(head);
            ListNode *last, *first, *curr = head;
            while (curr != mid) {
                last = curr;
                curr = curr->next;
            }
            last->next = nullptr;
            first = head;
            first = reverseList(first);
            if (length % 2) {
                curr = curr->next;
            }
            while (curr != nullptr) {
                if (curr->val != first->val) return false;
                curr = curr->next;
                first = first->next;
            }
            return true;
        }
};

int main (int argc, char *argv[]) {

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    //    head->next->next->next->next->next = new ListNode(1);
    print(head);

    Solution sol;
    std::cout << sol.isPalindrome(head) << "\n";
    return 0;
}

