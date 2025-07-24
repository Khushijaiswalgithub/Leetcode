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
    void f(TreeNode* root,int sum,int &t){
        if(root==NULL) return;
        sum=sum*10+root->val;
        if(root->left==NULL && root->right==NULL){
            t+=sum;
        } 
        f(root->left,sum,t);
        f(root->right,sum,t);

    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        int t=0;
        f(root,sum,t);
        return t;
    }
};