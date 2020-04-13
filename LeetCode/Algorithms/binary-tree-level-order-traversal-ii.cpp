class Solution {
    void levelorder_util(TreeNode *root, vector<vector<int>> & res, int level){
        if (root) {
            res.push_back({});
            res[level].push_back(root->val);
            levelorder_util(root->left, res, level+1);
            levelorder_util(root->right, res, level+1);
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        levelorder_util(root, res, 0);
        while (res.back().empty()) {
            res.pop_back();
        }
        vector<vector<int>> result(res.rbegin(), res.rend());
        return result;
    }
};
