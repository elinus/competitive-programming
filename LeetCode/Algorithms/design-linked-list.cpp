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
            if (!head || index < 0 || index >= length) return -1;
            Node *curr = head;
            while (index--) {
                curr = curr->next;
            }
            if (curr) return curr->data;
            return -1;
        }

        /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
        void addAtHead(int val) {
            Node *nn = new Node(val);
            if (!head) {
                last = nn;
            }
            nn->next = head;
            head = nn;
            length++;
        }

        /** Append a node of value val to the last element of the linked list. */
        void addAtTail(int val) {
            Node *nn = new Node(val);
            if (!last) {
                nn->next = head;
                head = nn;
            } else {
                last->next = nn;
            }
            last = nn;
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
            } else {
                Node *nn = new Node(val);
                Node *curr = head, *prev = nullptr;
                while (index--) {
                    prev = curr;
                    curr = curr->next;
                }
                if (prev) prev->next = nn;
                nn->next = curr;
                length++;
            }
        }

        /** Delete the index-th node in the linked list, if the index is valid. */
        void deleteAtIndex(int index) {
            if (index < 0 || index >= length) return;
            if (index == 0) {
                if (length == 1) {
                    head = nullptr;
                    last = nullptr;
                } else {
                    head = head->next;
                }
            } else {
                Node *curr = head, *prev = nullptr;
                while (index--) {
                    prev = curr;
                    curr = curr->next;
                }
                if (curr == last) {
                    prev->next = nullptr;
                    last = prev;
                } else if (curr->next) {
                    prev->next = curr->next;
                }
            }
            length--;
        }

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
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtHead(4);
    obj->addAtHead(5);
    obj->print();
    obj->addAtTail(1);
    obj->addAtTail(2);
    obj->addAtTail(3);
    obj->addAtTail(4);
    obj->addAtTail(5);
    obj->print();
    obj->deleteAtIndex(10);
    obj->print();
    obj->deleteAtIndex(0);
    obj->print();
    obj->deleteAtIndex(7);
    obj->print();

/*    obj->addAtIndex(5, 0);
    obj->addAtIndex(0, 6);
    obj->addAtIndex(12, 7);
    obj->addAtIndex(12, 6);
    obj->print();*/
    std::cout << "# " << obj->get(0) << "\n";
    std::cout << "# " << obj->get(12) << "\n";
    std::cout << "# " << obj->get(-1) << "\n";
    std::cout << "# " << obj->get(14) << "\n";
    std::cout << "# " << obj->get(5) << "\n";
    return 0;
}
