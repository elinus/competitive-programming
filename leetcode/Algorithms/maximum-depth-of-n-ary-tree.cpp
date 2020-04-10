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
    int max = 0, depth = 0;
public:
    int maxDepth(Node* root) {
        
        if (root) {
            depth++;
            if (depth > max) max = depth;
            for(int i = 0; i < root->children.size(); ++i) {
                maxDepth(root->children[i]);
            }
            depth--;
        }
        return max;
    }
};
