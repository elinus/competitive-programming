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
    void traverse(TreeNode *root, unordered_map<int, int> & m) {
        if (root) {
            if (m.find(root->val) != m.end())
                m[root->val] += 1;
            else 
                m[root->val] = 1;
            traverse(root->left, m);
            traverse(root->right, m);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> m;
        traverse(root, m);
        int max = INT_MIN;
        for (auto i = m.begin(); i != m.end(); ++i) {
            if (i->second > max) max = i->second; 
        }
        vector<int> answer;
        for (auto i = m.begin(); i != m.end(); ++i) {
            if (i->second == max) answer.push_back(i->first); 
        }
        return answer;
    }
};
