class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        unordered_map<char,int>mp,mp1;
        unordered_set<char>st;
        unordered_set<char>st1;
        for(auto ch:word1){
            mp[ch]++;
            st.insert(ch);
        }
        for(auto ch:word2){
            mp1[ch]++;
            st1.insert(ch);
        }
        if(st!=st1) return false;
        vector<int>a,a1;
        for(auto it:mp){
            a.push_back(it.second);
        }
        for(auto it:mp1){
            a1.push_back(it.second);
        }
        sort(a.begin(),a.end());
        sort(a1.begin(),a1.end());
        return a==a1;
    }
};