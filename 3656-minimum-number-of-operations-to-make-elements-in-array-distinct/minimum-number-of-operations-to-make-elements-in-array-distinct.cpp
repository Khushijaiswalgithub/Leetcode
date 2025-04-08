class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i+1);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]].size()>1){
                int m=mp[nums[i]].size();
                maxi=max(mp[nums[i]][m-2],maxi);
            }
        }
        if(maxi%3==0){
            return maxi/3;
        }
        else{
            return (maxi/3)+1;
        }
        
    }
};