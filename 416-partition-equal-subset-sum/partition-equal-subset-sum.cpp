class Solution {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        // code here
        int n=nums.size();
        vector<vector<bool>> dp(n,vector<bool> (target+1));
        for(int i=0;i<n;i++){
            dp[i][0]=true;    
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<target+1;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=nottake || take;
            }
        }
        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

        }
        if(sum%2==0){
           int target=sum/2;
            return isSubsetSum(nums,target);
        }
        else{
            return false;
        }
    
        
    }
};