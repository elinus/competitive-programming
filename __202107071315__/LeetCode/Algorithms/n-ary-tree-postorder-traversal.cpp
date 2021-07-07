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
    void postorder_util(Node *root, vector<int> & vec) {
        if (root) {
            for (int i = 0; i < root->children.size(); ++i) {
                postorder_util(root->children[i], vec);
            }
            vec.push_back(root->val);
        }
    }
    public:
    vector<int> postorder(Node* root) {
        vector<int> vec;
        postorder_util(root, vec);
        return vec; 
    }
};
