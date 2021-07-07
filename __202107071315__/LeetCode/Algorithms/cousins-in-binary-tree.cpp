/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void inorder(TreeNode* root, TreeNode* parent, int n, int depth, pair<TreeNode*, int>& p) {
        if(!root) return;
        inorder(root->left, root, n, 1 + depth, p);
        if(root->val == n) {
            p.first = parent;
            p.second = depth;
            return;
        }
        inorder(root->right, root, n, 1 + depth, p);    
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        pair<TreeNode*, int> p1, p2;
        inorder(root, root, x, 0, p1);
        inorder(root, root, y, 0, p2);
        return p1.first != p2.first && p1.second == p2.second;
    }
};

