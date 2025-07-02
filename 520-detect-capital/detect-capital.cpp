class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        vector<int>s(n,0);
        for (int i=0;i<n;i++){
            if(isupper(word[i])){
                s[i]=1;
            }
          
        }
        int ans=0;
        for (int i=0;i<n;i++){
            ans+=s[i];
          
        }
        if(ans==n) return true;
        else if(s[0]==1 && ans==1) return true;
        else if(ans==0) return true;
        else return false;

        
    }
};