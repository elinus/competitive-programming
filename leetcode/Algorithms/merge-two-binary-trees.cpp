class Solution {
    TreeNode* copy(TreeNode *root, TreeNode *new_root) {
        if(root != nullptr){
            if (new_root) new_root->val += root->val;
            else new_root = new TreeNode(root->val);
            new_root->left = copy(root->left, new_root->left);
            new_root->right = copy(root->right, new_root->right);
        } 
        return new_root;
    }

public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return nullptr;
        if (!t1) return t2;
        if (!t2) return t1;
        TreeNode *root = nullptr;
        root = copy(t1, root);
        return copy(t2, root);
    }
};
