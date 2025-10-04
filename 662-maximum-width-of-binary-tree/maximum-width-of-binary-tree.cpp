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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
    
        int ans=0;
        while(!q.empty()){
            
            int n=q.size();
            long long mini=q.front().second;
            long long first,last;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().first;
                long long x=(q.front().second)-mini;
                if(i==0) first=x;
                if(i==n-1) last=x;
                q.pop();
                if(node->left){
                    q.push({node->left,2*x+1});
                }
                if(node->right){
                    q.push({node->right,2*x+2});
                }
                
                
            }
            ans=max((int)(last-first+1),ans);

        } 
        return ans;
    }
};