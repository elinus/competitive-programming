#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

void print(ListNode* head, const std::string &tag) {
    std::cout << "[ " << tag << " ] ";
    ListNode *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}


class Solution {
    private:
        ListNode* sortedMerge(ListNode *a, ListNode *b) {
            ListNode *result = nullptr;
            if (!a) return b;
            else if (!b) return a;

            if (a->val <= b->val) {
                result = a;
                result->next = sortedMerge(a->next, b);
            } else {
                result = b;
                result->next = sortedMerge(a, b->next);
            }
            
            return result;
        }
        void splitInHalf(ListNode *head, ListNode **front, ListNode **back) {
            ListNode *fast = head->next, *slow = head;
            while (fast) {
                fast = fast->next;
                if (fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            *front = head;
            *back = slow->next;
            slow->next = nullptr;
        }
    public:
        ListNode* sortList(ListNode *head) {
            ListNode *a = nullptr, *b = nullptr;
            if (!head || !head->next) return head;
            splitInHalf(head, &a, &b);
            a = sortList(a);
            b = sortList(b);
            head = sortedMerge(a, b);
            return head;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    print(head, "start");

    Solution sol;
    print(sol.sortList(head), "end");

    return 0;
}

