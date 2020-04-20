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
    int maxDepth(TreeNode* node) {
        if (node == NULL) return 0;
        else return 1 + max(maxDepth(node->left), maxDepth(node->right));
    }   
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        int deepest = maxDepth(root);
        queue<TreeNode*> queue_;
        queue_.push(root);
        queue_.push(nullptr);
        int level = 1;
        int sum = 0;
        while (!queue_.empty()) {
            TreeNode *node = queue_.front();
            
            queue_.pop();
            if (!node) {
                if (!queue_.empty()) queue_.push(nullptr);
                level++;
            } else {
                if (level == deepest) sum += node->val;
                //cout << node->val << " " << level << endl;
                if (node->left) queue_.push(node->left);
                if (node->right) queue_.push(node->right);
            }
        }
        return sum;
    }
};
