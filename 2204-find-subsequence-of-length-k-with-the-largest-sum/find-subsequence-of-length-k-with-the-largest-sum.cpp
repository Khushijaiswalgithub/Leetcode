class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>mx;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mx.push_back({nums[i],i});
        }
        sort(mx.begin(),mx.end(),[](auto &a,auto &b){
           return a.first>b.first;
        });
        vector<pair<int,int>>topk;
        for(int i=0;i<k;i++){
           topk.push_back(mx[i]);
        }
        sort(topk.begin(),topk.end(),[](auto &a,auto &b){
           return a.second<b.second;
        });
        vector<int>res;
        for(auto it:topk){
            res.push_back(it.first);
        }
        return res;
    }
};