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
    int sum = 0;
    void calc_sum(vector<int> & vec) {
        int num = 0;
        int p = 0;
        for(auto it = vec.rbegin(); it != vec.rend(); ++it) {
            num += (*it) * pow(2, p++);
        }
        sum += num;
    }
    void postorder(TreeNode *root, vector<int> & vec) {
        if (root) {
            vec.push_back(root->val);
            postorder(root->left, vec);
            postorder(root->right, vec);
            if (!root->left && !root->right) {
                calc_sum(vec);
            }
            vec.pop_back();
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        vector<int> vec;
        postorder(root, vec);
        return sum;
    }
};
