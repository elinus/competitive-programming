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
    void insert(TreeNode *root, int val) {
        if (val < root->val) {
            if (!root->left) root->left = new TreeNode(val);
            else insert(root->left, val);
        } else if (val > root->val) {
            if (!root->right) root->right = new TreeNode(val);
            else insert(root->right, val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) root = new TreeNode(val); 
        else insert(root, val);
        return root;
    }
};
