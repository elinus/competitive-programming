/*
// Definition for a Node.
class Node {
public:
int val;
vector<Node*> children;

Node() {}

Node(int _val) {
val = _val;
}

Node(int _val, vector<Node*> _children) {
val = _val;
children = _children;
}
};
*/

class Solution {
    void preorder_util(Node *root, vector<int> & vec) {
        if (root) {
            vec.push_back(root->val);
            for (int i = 0; i < root->children.size(); ++i) {
                preorder_util(root->children[i], vec);
            }
        }
    }
    public:
    vector<int> preorder(Node* root) {
        vector<int> vec;
        preorder_util(root, vec);
        return vec;   
    }
};
