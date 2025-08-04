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
    void func(TreeNode* root,int level,vector<int>&q){
        if(root==NULL) return ;
        if(level==q.size()) q.push_back(root->val);
        func(root->right,level+1,q);
        func(root->left,level+1,q);


    }
    vector<int> rightSideView(TreeNode* root) {
        int level=0;
        vector<int>q;
        func(root,level,q);
        
        return q;
        
    }
};