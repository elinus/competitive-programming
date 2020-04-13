class Solution {
     bool preorder(TreeNode *root, int sum) {
        if(root) {
            sum -= root->val;
            if (root->left == nullptr && root->right == nullptr && sum == 0) {
                return true;
            }
            if (preorder(root->left, sum)) return true;
            if (preorder(root->right, sum)) return true;
            
        }
        return false;
    }

public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (preorder(root, sum)) return true;
        return false;
    }
};
