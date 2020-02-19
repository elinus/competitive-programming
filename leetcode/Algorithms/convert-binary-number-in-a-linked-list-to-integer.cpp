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

        int pow(int p) {
            int n = 1;
            while (p--) n *= 2;
            return n;
        }

    public:
        int getDecimalValue(ListNode* head) {
            if (!head) return 0;
            head = reverseList(head);
            ListNode *curr = head;
            int index = 0, dec_val = 0;
            while (curr) {
                dec_val += (curr->val * pow(index++));
                curr = curr->next;
            }
            return dec_val;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(0);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    print(head);

    Solution sol;
    std::cout << sol.getDecimalValue(head) << "\n:";
    return 0;
}

