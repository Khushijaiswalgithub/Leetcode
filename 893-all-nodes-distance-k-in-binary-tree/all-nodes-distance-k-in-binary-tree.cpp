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
    void marksParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;

            }
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;

            }

        }
             
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        marksParents(root,parent,target);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int c=0;
        while(!q.empty()){
            if(c++ == k) break;
            int n=q.size();
            for(int i=0;i<n;i++){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && !vis[node->left]){
                q.push(node->left);
                vis[node->left]=true;

            }
             if(node->right && !vis[node->right]){
                q.push(node->right);
                vis[node->right]=true;

            }
             if(parent[node] && !vis[parent[node]]){
                q.push(parent[node]);
                vis[parent[node]]=true;

            }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();

        }
        return ans;
    }
    
};