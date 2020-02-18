#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {} 
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *curr_ptr = NULL, *head_ptr = NULL;
            stack<ListNode*> st;
            while (l1 != NULL && l2 != NULL) {
                if (l1->val <= l2->val) {
                    st.push(l1);
                    l1 = l1->next;
                } else {
                    st.push(l2);
                    l2 = l2->next;
                }
            }

            while (l1 != NULL) {
                st.push(l1);
                l1 = l1->next;
            }

            while (l2 != NULL) {
                st.push(l2);
                l2 = l2->next;
            }

            while (!st.empty()) {
                curr_ptr = st.top();
                st.pop();
                //curr_ptr->next = NULL;
                if (head_ptr == NULL) {
                    head_ptr = curr_ptr;
                } else {
                    curr_ptr->next = head_ptr;
                    head_ptr = curr_ptr;
                }
            }

            return head_ptr;
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

    Solution sol;
    /* Code */

    return 0;
}

