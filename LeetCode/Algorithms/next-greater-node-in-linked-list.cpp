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
        std::vector<int> nextLargerNodes(ListNode *head) {
            head = reverse(head);
            ListNode dummy(0);
            ListNode *last = &dummy, *curr = head, *prev = nullptr;
            int last_val = -1;
            while (curr) {
                if (!prev) {
                    last->next = new ListNode(0);
                    last_val = 0;
                    last = last->next;
                } else {
                    if (prev->val > curr->val) {
                        last->next = new ListNode(prev->val);
                        last_val = prev->val;
                        last = last->next;
                    } else if (last->val > curr->val) {
                        last->next = new ListNode(last_val);
                        last_val = last->val;
                        last = last->next;
                    } else if (curr->val > prev->val && curr->val > last->val) {
                        last->next = new ListNode(0);
                        last_val = 0;
                        last = last->next;
                    }
                }
                prev = curr;
                curr = curr->next;
            }
            last->next = nullptr;
            std::vector<int> res(getListLength(head));
            curr = reverse(dummy.next);
            int i = 0;
            while (curr) {
                res[i++] = curr->val;
                curr = curr->next;
            }
            return res;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(7);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(1);
    print(head);

    Solution sol;
    auto res = sol.nextLargerNodes(head);
    for (auto it = res.begin(); it != res.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    return 0;
}

