class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int o=0;
        int e=0;
        int alt=1;
        for(auto it:nums){
            if(it%2==0) e++;
            else o++;
        }
        int p=nums[0]%2;
        for(auto it:nums){
            if(it%2!=p){
                alt++;
                p=it%2;
            }
            
        }
        return max({e,o,alt});
    }
};