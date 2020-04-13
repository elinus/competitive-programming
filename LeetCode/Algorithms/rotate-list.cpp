#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    private:
        int getListLength(ListNode *head) {
            ListNode *curr = head;
            int length = 0;
            while (curr) {
                length++;
                curr = curr->next;
            }
            return length;
        }
    public:
        ListNode* rotateRight(ListNode *head, int k) {
            if (!head || !k) return head;
            int len = getListLength(head), counter;
            while (k > len) {
                k -= len;
            }
            counter = len - k;
            ListNode *tail = head, *curr = head, *prev = nullptr;
            while (tail) {
                prev = tail;
                tail = tail->next;
            }
            prev->next = head;

            while (curr && counter--) {
                prev = curr;
                curr = curr->next;
            }

            prev->next = nullptr;
            head = curr;

            return head;
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
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);

    Solution sol;
    print(sol.rotateRight(head, 2));

    return 0;
}

