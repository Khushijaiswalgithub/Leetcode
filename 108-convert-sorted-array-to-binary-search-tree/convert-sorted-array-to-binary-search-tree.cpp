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
    TreeNode* bst(vector<int>& nums,int l,int h){
        if(l>h) return NULL;
        int mid=(l+h)/2;
        TreeNode* node=new TreeNode(nums[mid]);
        node->left=bst(nums,l,mid-1);
        node->right=bst(nums,mid+1,h);
        return node;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        int l=0;
        int h=n-1;
        
        return bst(nums,l,h);
    }
};