class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int maxi=0;
        for(auto& [num, count]:mp){
            if(mp.count(num+1)){
                maxi=max(maxi,count+mp[num+1]);
            }
        }
        return maxi;
        
    }
};