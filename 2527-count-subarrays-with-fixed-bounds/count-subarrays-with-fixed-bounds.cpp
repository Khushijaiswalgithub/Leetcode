class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int mini=-1;
        int maxi=-1;
        int c=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                c=i;
            }
            if(nums[i]==minK){
                mini=i;
            }
            if(nums[i]==maxK){
                maxi=i;
            }
            long long s=min(mini,maxi);
            long long temp=s-c;
            if(temp>0){
                ans+=temp;
            }

            

        }
        return ans;
    }
};