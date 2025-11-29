class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int s=0;
        for(auto it:nums){
            s+=it;

        }
        int ans =s%k;
        return ans;
    }
};