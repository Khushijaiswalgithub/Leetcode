class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int j=n-1;j>=2;j--){
            int i=0;
            int k=j-1;
            while(i<k){
                int sum=nums[i]+nums[k];
                if(sum>nums[j]){
                    ans+=(k-i);
                    k--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
        
    }
};