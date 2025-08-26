class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxi=0;

        int num=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            maxi=max(sum,maxi);
            num=max(num,nums[i]);

        }
        if(maxi==0) return num;
        return maxi;
    }
};