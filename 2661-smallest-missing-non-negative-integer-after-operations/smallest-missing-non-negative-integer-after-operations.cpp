class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            int x=((it%value)+value)%value;
            mp[x]++;
        }
        int mex=0;
        while(mp[mex%value]>0){
            mp[mex%value]--;
            mex++;
        }
        return mex;
        
    }
};