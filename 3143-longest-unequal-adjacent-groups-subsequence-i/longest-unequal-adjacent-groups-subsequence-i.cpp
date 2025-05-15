class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string>ans;
        ans.push_back(words[0]);
        int c=groups[0];
        for(int i=1;i<n;i++){
            if(groups[i]!=c){
                ans.push_back(words[i]);
                c=groups[i];
            }
            

        }
        return ans;
    }
};