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
    void preorder(TreeNode *root, int L, int R, int & sum) {
        if (root) {
            if (root->val >= L && root->val <= R) 
                sum += root->val;
            preorder(root->left, L, R, sum);
            preorder(root->right, L, R, sum);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        preorder(root, L, R, sum);
        return sum;
    }
};
