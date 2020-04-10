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
    TreeNode* new_root = nullptr, *node = nullptr;
    void inorder(TreeNode *root) {
        if (root) {
            inorder(root->left);
            if (!node) {
                new_root = new TreeNode(root->val);
                node = new_root;
            } else {
                node->right = new TreeNode(root->val);
                node = node->right;
            }
            inorder(root->right);
        }
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return new_root;
    }
};
