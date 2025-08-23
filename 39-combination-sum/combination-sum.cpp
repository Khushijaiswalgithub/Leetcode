class Solution {
public:
    void combi(int ind,vector<vector<int>> &ds,vector<int> &ans,int target,vector<int> candidates,int n){
        if(ind==n){
            if(target==0){
                ds.push_back(ans);
            }
            return;
        }
        if(candidates[ind]<=target){
        ans.push_back(candidates[ind]);
        combi(ind,ds,ans,target-candidates[ind],candidates,n);
        ans.pop_back();
        }
        combi(ind+1,ds,ans,target,candidates,n);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        int ind=0;
        vector<vector<int>> ds;
        vector<int> ans;
        combi(ind,ds,ans,target,candidates,n);
        return ds;

        
    }
};