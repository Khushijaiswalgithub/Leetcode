class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m!=n)  return false;
        unordered_map<char,char>mp;
        unordered_set<char>st(t.begin(),t.end());
        
        for(int i=0;i<n;i++){
            
            mp[s[i]]=t[i];
        }
        if(st.size()!=mp.size()) return false;
        string str="";
        for(auto it:s){
            str+=mp[it];

        }
        return str==t;
    }
};