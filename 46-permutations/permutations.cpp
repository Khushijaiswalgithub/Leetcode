class Solution {
public:
    void f(vector<int>& nums, vector<int>& fre, vector<vector<int>>& ans, vector<int>& t) {
        if (t.size() == nums.size()) {
        ans.push_back(t);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!fre[i]) {                 // if nums[i] is not used yet
            t.push_back(nums[i]);      // choose nums[i]
            fre[i] = 1;                // mark as used
            f(nums, fre, ans, t);      // recurse
            fre[i] = 0;                // unmark (backtrack)
            t.pop_back();              // remove last element
        }
    }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>fre(n,0);
        vector<int>t;
        vector<vector<int>>ans;
        f(nums,fre,ans,t);
        return ans;
        
    }
};