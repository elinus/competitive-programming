#include <iostream>
#include <vector>
#include <climits>

using namespace std;

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
        ListNode* mergeKLists(vector<ListNode*> &lists) {
            ListNode *head = nullptr, *last = nullptr;
            int total_nodes = 0;
            for (auto it = lists.begin(); it != lists.end(); ++it) {
                total_nodes += getListLength(*it);
            }
            ListNode dummy(0);
            ListNode *tail = &dummy;
            for (int i = 0; i < total_nodes; i++) {
                int min = INT_MAX, min_idx = 0;
                for (int j = 0; j < lists.size(); j++) {
                    if (lists[j] != nullptr && lists[j]->val < min) {
                        min = lists[j]->val;
                        min_idx = j;
                    }
                }
                tail->next = lists[min_idx];
                tail = tail->next;
                lists[min_idx] = lists[min_idx]->next;
            }
            return dummy.next;
        }
};

int main (int argc, char *argv[]) {
    
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(4);
    head1->next->next = new ListNode(5);
    
    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    
    ListNode *head3 = new ListNode(2);
    head3->next = new ListNode(6);
    vector<ListNode*> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);

    for (auto it = lists.begin(); it != lists.end(); ++it) {
        print(*it);
    }

    Solution sol;
    print(sol.mergeKLists(lists));
    return 0;
}

