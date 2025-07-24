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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
    TreeNode* build(vector<int>&preorder,int spre,int epre,vector<int>&inorder,int sin,int ein,unordered_map<int,int>&mp){
        if(spre>epre || sin>ein) return NULL;
        TreeNode* root= new TreeNode(preorder[spre]);
        int inroot=mp[preorder[spre]];
        int nleft=inroot-sin;
        root->left=build(preorder,spre+1,spre+nleft,inorder,sin,inroot-1,mp);
        root->right=build(preorder,spre+nleft+1,epre,inorder,inroot+1,ein,mp);
        return root;
    }
};