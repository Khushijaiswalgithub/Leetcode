class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i+1;
        }
        int maxi=0;
        int start=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
           maxi=max(maxi,mp[s[i]]);
           if(i+1==maxi){
            ans.push_back(maxi-start);
            start=i+1;

           } 
        }
        return ans;
    }
};