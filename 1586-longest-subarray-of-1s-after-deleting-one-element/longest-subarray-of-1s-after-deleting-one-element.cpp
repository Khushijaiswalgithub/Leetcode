class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int i=0;
        int j=0;
        int ind=-1;
        int maxi=0;
        while(j<n){
            if(nums[j]==0){
                i=ind+1;
                ind=j;
            }

            maxi=max(maxi,j-i);
            j++;

        }
        return maxi;
    }
};