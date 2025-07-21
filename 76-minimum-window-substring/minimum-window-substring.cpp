class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int l=0;
        int r=0;
        int m=t.size();
        int n=s.size();
        int mini=INT_MAX;
        int cnt=m;
        int sind=-1;
        while(r<n){
            if(mp[s[r]]>0){
                cnt--;
               
            }
            mp[s[r]]--;
            while(cnt==0){
                if(r-l+1<mini){
                    mini=r-l+1;
                    sind=l;
                }
                
                
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt++;
                l++;

            }
            r++;
        }
        return sind==-1? "":s.substr(sind,mini);
        
    }
};