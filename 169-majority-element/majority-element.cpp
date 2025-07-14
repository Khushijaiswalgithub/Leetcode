class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int x=n/2;
        int ans=-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp.find(nums[i])!=mp.end() && mp[nums[i]]>x){
                 ans=nums[i];
                 break;
            }
            
        }
        return ans;
    }
};