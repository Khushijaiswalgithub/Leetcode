class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int res=0;
        unordered_map<string,int>mp;
        for(auto it:words){
            string s=it;
            reverse(s.begin(),s.end());
            if(mp[s]>0){
                res+=4;
                mp[s]--;
                
            }
            else{
                mp[it]++;
            }
        }
        for(auto it:mp){
            if(it.first[0]==it.first[1]  && it.second>0){
                res+=2;
                break;

            }
        }
        return res;
    }
};