class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(auto it:s){
            mp[it]++;
            
        }
        int maxi=-1;
        int mini=INT_MAX;
        for(auto it:mp){
            if(it.second%2==0){
                mini=min(mini,it.second);
            }
            else{
                maxi=max(maxi,it.second);
            }
        }
        return maxi-mini;

        
    }
};