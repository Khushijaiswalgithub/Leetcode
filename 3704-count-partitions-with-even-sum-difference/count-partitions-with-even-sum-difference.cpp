class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int t=0;
        for(auto it:nums){
            t+=it;
        }
        int ans=0;
        int s=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            s+=nums[i];
            if((t-2*s)%2==0){
                ans++;
            }

        }
        return ans;
    }
};