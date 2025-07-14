class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int j=0;
        int k=0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
               nums[j]=nums[i];
               j++;
               k++;
            }
        
            mp[nums[i]]++;

        }
    
        
        return k;
    }
};