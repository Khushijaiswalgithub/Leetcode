class Solution {
public:
    string reverseWords(string s) {
        vector<string>vec;
        int st=0;
        
        int n=s.size();
        int i=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            st=i;
            while (i < n && s[i] != ' ') i++;
            if (st < i) {
               vec.push_back(s.substr(st, i - st));
            }
            
        }
        string ans="";
        for(int i=vec.size()-1;i>=0;i--){
           ans+=vec[i];
           if(i!=0) ans+=" ";
           
        }
        return ans;
        
    }
};