class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        
        for(int j=1;j<n-1;j++){
            int lmaxi=0;
            int rmaxi=0;
            for(int i=0;i<j;i++){
                lmaxi=max(nums[i],lmaxi);
            }
             for(int k=j+1;k<n;k++){
                rmaxi=max(nums[k],rmaxi);
            }
            long long ans=static_cast<long long>(lmaxi-nums[j])*rmaxi;
            maxi=max(maxi,ans);


        }
        if(maxi<0){
            return 0;
        }
        return maxi;
    }
};