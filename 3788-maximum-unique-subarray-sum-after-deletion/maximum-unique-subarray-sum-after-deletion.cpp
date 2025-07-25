class Solution {
public:
    int maxSum(vector<int>& nums) {
      
      int n=nums.size();
      int sum=0;
      int maxi=INT_MIN;
      vector<int>vis(101);
      for(int i=0;i<n;i++){
        maxi=max(maxi,nums[i]);
        if(nums[i]>0 && !vis[nums[i]]){
            sum+=nums[i];
            vis[nums[i]]=1;
        }
        
      }
      if(maxi<=0) return maxi;
      return sum;
    }
};