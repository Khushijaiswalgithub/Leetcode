class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxi=0;
        unordered_map<int,int>mp;
        int score=0;
        while(r<n){
            mp[nums[r]]++;
            score+=nums[r];
            
            while(l<=r && mp.size()!=r-l+1){
                mp[nums[l]]--;
                score-=nums[l];
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(mp.size()==r-l+1){
                maxi=max(maxi,score);
            }
            r++;
        }
        return maxi;
        
    }
};