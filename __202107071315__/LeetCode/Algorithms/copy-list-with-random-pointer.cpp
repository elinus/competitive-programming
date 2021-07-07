#include <iostream>

struct Node {
    int val;
    Node *next;
    Node *random;
    Node(int x): val(x), next(nullptr), random(nullptr) {} 
};

void print(Node* head) {
    Node *curr = head;
    while (curr) {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}


class Solution {
    Node* newNode(int data) {
        return new Node(data);
    }
    public:
        Node* copyRandomList(Node *head) {
            Node *curr = head, *copy, *temp;
            while (curr) {
                Node *next = curr->next;
                Node *new_node = newNode(curr->val);
                new_node->next = next;
                curr->next = new_node;
                curr = next;
            }
            curr = head;
            while (curr) {
                if (curr->next)
                    curr->next->random = curr->random ? curr->random->next : curr->random;
                curr = curr->next ? curr->next->next : curr->next; 
            }
            curr = head;
            copy = head->next;
            temp = copy;
            while (curr) {
                curr->next = curr->next ? curr->next->next : curr->next;
                copy->next = copy->next ? copy->next->next : copy->next;
                curr = curr->next;
                copy = copy->next;
            }
            return temp;
        }
};

int main (int argc, char *argv[]) {
    
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    print(head);

    Solution sol;
    print(sol.copyRandomList(head));

    return 0;
}

