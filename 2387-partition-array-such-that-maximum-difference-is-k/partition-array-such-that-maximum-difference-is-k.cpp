class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int x=nums[0];
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i]-x>k){
                c++;
                x=nums[i];

            }
        }
        return c+1;
        
    }
};