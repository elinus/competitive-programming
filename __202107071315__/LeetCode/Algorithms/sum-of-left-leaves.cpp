class Solution {
    void preorder(TreeNode *root, int & value) {
        if(root) {
            if (root->left && root->left->left == nullptr && root->left->right == nullptr) value += root->left->val;
            preorder(root->left, value);
            preorder(root->right, value);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preorder(root, sum);
        return sum;
    }
};
