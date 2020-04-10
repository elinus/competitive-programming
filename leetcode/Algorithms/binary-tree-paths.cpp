class Solution {
    string print(vector<int> vec) {
        string res;
        for (int i = 0; i < vec.size() - 1; ++i) {
            res += to_string(vec[i]) + "->";
        }
        res += to_string(vec[vec.size() -1 ]);
        return res;
    }
    
    void preorder(TreeNode *root, vector<int> & path, vector<string> & str_path) {
        if(root) {
            path.push_back(root->val);
            preorder(root->left, path, str_path);
            preorder(root->right, path, str_path);
            if (root->left == nullptr && root->right == nullptr) {
                str_path.push_back(print(path));
            }
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> str_path;
        vector<int> path;
        preorder(root, path, str_path);
        return str_path;
    }
};
