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
    unordered_set<int> uset; 
    
public:
    bool findTarget(TreeNode* root, int k) {
        bool ret = false;
        if (root) {
            if (uset.find(k - root->val) != uset.end())
                return true;
            else uset.insert(root->val);
            if (findTarget(root->left, k)) return true;
            if (findTarget(root->right, k)) return true;
        }
        return ret;
        
    }
};
