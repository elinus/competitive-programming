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
        ListNode* getFixedLastNode(ListNode *head) {
            ListNode *curr = head, *prev = nullptr;
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            }
            if (!prev) return nullptr;
            else prev->next = nullptr;
            return curr;
        }
    public:
        void reorderList(ListNode *head) {
            ListNode *prev = nullptr, *curr = head, *last = nullptr;
            while (curr) {
                last = getFixedLastNode(curr);
                if (!last) {
                    break;
                }
                prev = curr;
                curr = curr->next;
                prev->next = last;
                last->next = curr;
            }
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
    print(head);

    Solution sol;
    sol.reorderList(head);
    print(head);

    return 0;
}

