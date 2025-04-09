class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int c=0;
        int s=0;
        for(auto it:mp){
            if(it.first>k){
                c++;
            }
            else if(it.first==k){
                s++;
            }
            else{
                return -1;
            }
        }
        
        return c;
    }
};