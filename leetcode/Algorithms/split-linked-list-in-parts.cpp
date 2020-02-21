#include <iostream>
#include <vector>

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
        int getListLength(ListNode *head) {
            int length = 0;
            ListNode *curr = head;
            while (curr) {
                length++;
                curr = curr->next;
            }
            return length;
        }
    public:
        std::vector<ListNode*> splitListToParts(ListNode* root, int k) {
            int length = getListLength(root);
            std::vector<int> list_lengths(k, 0);
            while (length) {
                for (int i = 0; i < k && length; i++) {
                    list_lengths[i]++;
                    length--;
                }
            }
            std::vector<ListNode*> res(k, nullptr);
            ListNode *curr = root, *prev = nullptr, *last = nullptr, *res_curr = nullptr;
            for (int i = 0; i < k; i++) {
                if (prev) prev->next = nullptr;
                res[i] = curr;
                
                while (list_lengths[i]--) {
                    prev = curr;
                    curr = curr->next;
                }
            }
            return res;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    print(head);

    Solution sol;
    sol.splitListToParts(head, 7);

    return 0;
}

