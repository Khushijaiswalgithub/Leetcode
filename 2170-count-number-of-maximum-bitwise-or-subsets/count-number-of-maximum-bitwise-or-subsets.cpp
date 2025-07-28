class Solution {
public:
 int  maxi=0;
    int f(vector<int>& nums,int n,int ind,int curr){
        if(ind==n){
            if(curr==maxi)return 1;
            else return 0;
        }
        int take=f(nums,n,ind+1,curr|nums[ind]);
        int nottake=f(nums,n,ind+1,curr);
        return take+nottake;

    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        for(auto it:nums) maxi|=it;
        return f(nums,n,0,0);
    }
};