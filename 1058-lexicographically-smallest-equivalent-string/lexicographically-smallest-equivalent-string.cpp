class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&mp,char x,vector<int>&visited){
        visited[x-'a']=1;
        char minchar=x;
        for(auto it:mp[x]){
            if(visited[it-'a']==0){
            minchar=min(minchar,dfs(mp,it,visited));
            }
        }
        return minchar;

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>mp;
        int n=s1.size();
        int m=baseStr.size();
        for(int i=0;i<n;i++){
            mp[s1[i]].push_back(s2[i]);
            mp[s2[i]].push_back(s1[i]);
        }
        string res="";
        
        for(int i=0;i<m;i++){
            vector<int>visited(26,0);
            char x=dfs(mp,baseStr[i],visited);
            res.push_back(x);
        }
        return res;
    }
};