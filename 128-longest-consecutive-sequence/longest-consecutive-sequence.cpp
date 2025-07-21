class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=1;
        int n=nums.size();
        unordered_map<int,int>mp;
        if(n==0) return 0;
        mp[nums[0]]=1;
        for(int i=1;i<n;i++){
            if(mp.find(nums[i]-1)!=mp.end()){
                mp[nums[i]]=mp[nums[i]-1]+1;
            }
            else{
                mp[nums[i]]=1;
            }
            maxi=max(maxi,mp[nums[i]]);

        }
        return maxi;
        
    }
};