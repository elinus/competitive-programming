class Solution {
    void postorder(TreeNode *root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            swap(root->left, root->right);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        postorder(root);
        return root;
    }
};
