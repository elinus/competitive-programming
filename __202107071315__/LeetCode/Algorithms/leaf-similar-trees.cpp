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
    vector<int> v1, v2;
    void preorder(TreeNode *root, vector<int> & v) {
        if (root) {
            if (!root->left && !root->right) {
                v.push_back(root->val);
            }
            preorder(root->left, v);
            preorder(root->right, v);
        }
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        preorder(root1, v1);
        preorder(root2, v2);
        return v1 == v2;
    }
};
