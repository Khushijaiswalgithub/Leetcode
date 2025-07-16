class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int t=1;
        int z=0;
        for(auto it:nums){
            if(it!=0){
                t*=it;
            }
            else{
                z++;
            }
        }
        int n=nums.size();
        vector<int>ans(n,0);
        if(z>1){
            return ans;

        }
        for(int i=0;i<n;i++){
            if(z){
            if(nums[i]!=0  ){
                ans[i]=0;
            }
            else{
                ans[i]=t;
            }
            }
            else{
                ans[i]=(t/nums[i]);
            }
            
        }
        return ans;
    }
};