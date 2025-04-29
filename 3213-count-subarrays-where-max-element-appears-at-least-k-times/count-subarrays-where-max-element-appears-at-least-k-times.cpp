class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        long long ans=0;
        int c=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        while(r<n){
            if(nums[r]==maxi){
                c++;
            }
            while(c==k){
                ans+=n-r;
                if(nums[l]==maxi){
                    c--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};