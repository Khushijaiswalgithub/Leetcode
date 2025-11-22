class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int x=nums[i]%3;
            ans+=min(3-x,x);
        }
        return ans;
    }
};