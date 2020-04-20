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
    void insert(TreeNode *root, int key) {
        if (key < root->val) {
            if (root->left)
                insert(root->left, key);
            else root->left = new TreeNode(key);
        } else if (key > root->val) {
            if (root->right)
                insert(root->right, key);
            else root->right = new TreeNode(key);
        }
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;
        TreeNode *root = nullptr;
        for (int i = 0; i < preorder.size(); ++i) {
            if (root == nullptr) {
                root = new TreeNode(preorder[i]);
            } else {
                insert(root, preorder[i]);
            }
        }
        return root;
    }
};
