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
    unordered_map<int,int>mp;
    int maxi=0;
    void depth(TreeNode* root,int d){
        if(root==NULL){
            return;
        }
        mp[root->val]=d;
        depth(root->left,d+1);
        depth(root->right,d+1);
        maxi=max(maxi,d);

    }
    TreeNode* lca(TreeNode* root){
        if(root==NULL || mp[root->val]==maxi){
            return root;
        }
        TreeNode* l=lca(root->left);
        TreeNode* r=lca(root->right);
        if(l!=NULL && r!=NULL){
            return root;
        }
        if(!l){
            return r;
        }
        
        return l;
        
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        depth(root,0);
        return lca(root);
    }
};