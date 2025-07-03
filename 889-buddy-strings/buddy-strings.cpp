class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        int n1=goal.size();
        if(n!=n1) return false;
        
        if (s == goal) {
        
          unordered_set<char> st(s.begin(), s.end());
          return st.size() < s.size();
        }
        vector<int>diff;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]) diff.push_back(i);
            
        }
        if(diff.size()>2) return false;
        return diff.size()==2 && s[diff[0]]==goal[diff[1]] && s[diff[1]]==goal[diff[0]];
        
        

    }
};