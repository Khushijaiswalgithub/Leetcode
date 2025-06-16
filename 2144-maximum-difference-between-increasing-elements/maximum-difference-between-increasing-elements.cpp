class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxid=-1;
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            if(mini<nums[i]){
                maxid=max(maxid,nums[i]-mini);
            }
            else{
                mini=nums[i];
            }
        }
        return maxid;
    }
};