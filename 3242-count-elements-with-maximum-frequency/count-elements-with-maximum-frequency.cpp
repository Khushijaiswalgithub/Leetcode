class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(auto it:nums){
            mp[it]++;
            maxi=max(maxi,mp[it]);
        }
        int sum=0;
        for(auto it:mp){
            if(it.second==maxi){
                sum+=it.second;
            }
        }
        return sum;
    }
};