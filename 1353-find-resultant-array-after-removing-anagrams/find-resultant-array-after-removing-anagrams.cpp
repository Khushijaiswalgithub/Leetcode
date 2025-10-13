class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       
        vector<string>ans;
        int n=words.size();
        string prev=words[0];
        sort(prev.begin(),prev.end());
        ans.push_back(words[0]);
        for(int i=1;i<n;i++){
            string x=words[i];
            sort(x.begin(),x.end());
            if(x!=prev){
                ans.push_back(words[i]);

            }
            prev=x;
        }
        
        
        
        return ans;
        
    }
};