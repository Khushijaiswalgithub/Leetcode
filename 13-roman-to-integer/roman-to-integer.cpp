class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int ans=mp[s[n-1]];
        for(int i=n-2;i>=0;i--){
           if(mp[s[i+1]]<=mp[s[i]]){
            ans+=mp[s[i]];
           }
           else{
             ans-=mp[s[i]];
           }
        }
        return ans;

            
        
    }
};