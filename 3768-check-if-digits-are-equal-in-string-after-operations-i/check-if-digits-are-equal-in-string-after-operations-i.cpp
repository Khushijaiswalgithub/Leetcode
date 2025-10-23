class Solution {
public:
    bool hasSameDigits(string s) {
        
        
        while(s.size()>2){
            int n=s.size();
        int st=s[0]-'0';
        string ans="";
            for(int i=1;i<n;i++){
            int e=s[i]-'0';
            ans.push_back(((st+e)%10)+'0');
            st=e;
            }
            s=ans;

        }
        if(s.size()==2 && s[0]==s[1] ) return true;
        return false;


        
        
    }
};