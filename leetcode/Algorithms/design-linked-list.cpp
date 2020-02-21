#include <iostream>

struct Node {
    int data;
    Node *next;
    Node(int data): data(data), next(nullptr) 
    {}
};

class MyLinkedList {
    private:
        Node *head, *last;
        int length;
    public:
        /** Initialize your data structure here. */
        MyLinkedList() {
            head = nullptr;
            last = nullptr;
            length = 0;
        }

        /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
        int get(int index) {
            if (!head || index < 0 || index > length) return -1;
            if (index == 0) return head->data;
            else if (index == length-1) return last->data;
            Node *curr = head;
            while (curr && index--) {
                curr = curr->next;
            }
            if (curr) return curr->data;
            return -1;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            Node *nn = new Node(val);
            if (!head) {
                head = nn;
                last = head;
            } else {
                nn->next = head;
                head = nn;
            }
            length++;
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            Node *nn = new Node(val);
            if (!last) {
                head = nn;
                last = head;
            } else {
                last->next = nn;
                last = nn;
            }
            length++;
        }
        
        /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
        void addAtIndex(int index, int val) {
            if (index < 0 || index > length) return;
            else if (index == 0) {
                addAtHead(val);
                return;
            } else if (index == length) {
                addAtTail(val);
                return;
            }
            Node *nn = new Node(val);
            Node *curr = head, *prev = nullptr;
            while (curr && index--) {
                prev = curr;
                curr = curr->next;
            }
            if (prev) prev->next = nn;
            nn->next = curr;
		    length++;
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            if (index < 0 || index > length) return;
            if (index == 0) {
                if (length == 1) {
                    head = nullptr;
                    last = nullptr;
                } else {
                    Node *curr = head;
                    head = head->next;
                    delete curr;
                }
                length--;
                return;
            }
            if (index == length) {
                Node *curr = head;
                while(curr && curr->next != last) {
                    curr = curr->next;
                }
                if (curr) {
                    Node *temp = last;
                    last = curr;
                    last->next = nullptr;
                    delete temp;
                }
                length--;
                return;
            }
            Node *curr = head;
            while (curr && --index) {
                curr = curr->next;
            }
            Node *temp = curr->next;
            if (curr->next->next) curr->next = curr->next->next;
            else curr->next = nullptr;
            delete temp;
            length--;
        }

        /* HELPER FUNCTIONS */

        void print() {
            Node *curr = head;
            while (curr) {
                std::cout << curr->data << " ";
                curr = curr->next;
            }
            std::cout << "\n";
        }
};

int main (int argc, char *argv[]) {
    MyLinkedList* obj = new MyLinkedList();
    obj->print();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->print();
    obj->addAtIndex(1, 2);
    obj->print();
    //std::cout << obj->get(0) << "\n";
    //std::cout << obj->get(10) << "\n";
    std::cout << obj->get(1) << "\n";
    std::cout << "---\n";
    obj->deleteAtIndex(1);
    obj->print();
    return 0;
}


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
