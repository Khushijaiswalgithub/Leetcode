class Solution {
public:
    void subsetsum(int ind,int n,int &x,vector<int>&d,vector<int>& nums){
        if(ind>=n){
            d.push_back(x);
            return;
        }
        x^=nums[ind];
        subsetsum(ind+1,n,x,d,nums);
        x^=nums[ind];
        subsetsum(ind+1,n,x,d,nums);

    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>d;
        int n=nums.size();
        int x=0;

        subsetsum(0,n,x,d,nums);
        int sum=0;
        for(int i=0;i<d.size();i++){
            sum+=d[i];

        }
        return sum;
        
    }
};