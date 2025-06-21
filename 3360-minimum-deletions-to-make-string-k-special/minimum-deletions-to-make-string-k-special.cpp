class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int>mp;
        
        for(char ch:word){
            mp[ch]++;
            
        }
        vector<int>c;
        for(auto it:mp){
          c.push_back(it.second);
        }
        int n=c.size();
        int res=INT_MAX;
        sort(c.begin(),c.end());
        for(int i=0;i<n;i++){
            int x=c[i];
            int d=0;
            for(int j=0;j<n;j++){
                if(c[j]>x+k){
                    d+=c[j]-x-k;
                    
                }
                else if(c[j]<x){
                    d+=c[j];
                }
            }
            res=min(res,d);
        }
        return res;
    
    }    
};