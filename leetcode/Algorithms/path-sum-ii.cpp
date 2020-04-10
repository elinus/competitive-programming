class Solution {

    void preorder(TreeNode *root, vector<int> & path, vector<vector<int>> & paths, int sum) {
        if(root) {
            sum -= root->val;
            path.push_back(root->val);
            preorder(root->left, path, paths, sum);
            preorder(root->right, path, paths, sum);
            if (root->left == nullptr && root->right == nullptr && sum == 0) {
                paths.push_back(path);
            }
            path.pop_back();
        }
    }

    public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> paths;
        preorder(root, path, paths, sum);
        return paths;
    }
};
