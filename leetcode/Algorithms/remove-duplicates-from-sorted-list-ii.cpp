#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    public:
        ListNode* deleteDuplicates(ListNode *head) {
            if (!head) return nullptr;
            ListNode *curr = head, *prev = nullptr;
            std::unordered_set<int> hs;
            while (curr) {
                prev = curr;
                curr = curr->next;
                if (curr != nullptr && curr->val == prev->val) {
                    while (curr != nullptr && curr->val == prev->val) {
                        ListNode* temp = curr;
                        curr = curr->next;
                        delete temp;
                    }
                    delete prev;
                    prev = nullptr;
                }
            }
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    print(head);

    Solution sol;
    print(sol.deleteDuplicates(head));
    

    return 0;
}

