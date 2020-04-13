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
    int height(TreeNode* node) { 
        if(node == nullptr) 
            return 0;  
        return 1 + max(height(node->left), height(node->right)); 
    }  
  
public:
    int diameterOfBinaryTree(TreeNode* tree) {
        if (tree == nullptr) return 0; 
        int lheight = height(tree->left); 
        int rheight = height(tree->right); 
        int ldiameter = diameterOfBinaryTree(tree->left); 
        int rdiameter = diameterOfBinaryTree(tree->right); 
        return max(lheight + rheight, max(ldiameter, rdiameter)); 
    }
};
