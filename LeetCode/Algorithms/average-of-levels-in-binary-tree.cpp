class Solution {
    void levelorder_util(TreeNode *root, vector<vector<int>> & res, int level){
        if (root) {
            res.push_back({});
            res[level].push_back(root->val);
            levelorder_util(root->left, res, level+1);
            levelorder_util(root->right, res, level+1);
        }
    }
    double average(vector<int> vec) {
        double sum = 0;
        for (int i:vec) {
            sum += i;
        }
        return sum / vec.size();
    }

public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return {};
        levelorder_util(root, res, 0);
        while (res.back().empty()) {
            res.pop_back();
        }
        vector<double> avg_vec(res.size());
        for(int i = 0; i < res.size(); ++i) {
            avg_vec[i] = average(res[i]);
        }
        return avg_vec;
    }
};
