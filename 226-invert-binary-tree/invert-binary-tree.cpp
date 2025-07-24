/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* right=f(root->right);
        TreeNode* left=f(root->left);
        
        root->right=left;
        root->left=right;
        return root;


    }
    TreeNode* invertTree(TreeNode* root) {
        return f(root);
        
        
    }
};