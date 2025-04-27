class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=2;i<n;i++){
            double f=nums[i-2];
            double s=nums[i-1];
            double t=nums[i];
            if((f+t)==(double)s/2){
                c++;
            }

        }
        return c;
        
    }
};