class Solution {
    void levelorder_util(Node *root, vector<vector<int>> & res, int level){
        if (root) {
            res.push_back({});
            res[level].push_back(root->val);
            for(int i = 0; i < root->children.size(); ++i) {
                levelorder_util(root->children[i], res, level+1);
            }
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        levelorder_util(root, res, 0);
        while (res.back().empty()) {
            res.pop_back();
        }
        return res;
    }
};
