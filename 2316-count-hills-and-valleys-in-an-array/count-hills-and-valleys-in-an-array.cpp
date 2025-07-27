class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return 0;
        vector<int>res;
        res.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                res.push_back(nums[i]);
            }
        }
        int c=0;
        for(int i=1;i<res.size()-1;i++){
            if(res[i-1]>res[i] && res[i]<res[i+1]){
                c++;

            }
            if(res[i-1]<res[i] && res[i]>res[i+1]){
                c++;

            }
        }
        return c;

        
    }
};