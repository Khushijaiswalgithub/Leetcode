class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string str="";
        str+=s[0];
        str+=s[1];
        if(n<3) return s;
        for(int i=2;i<n;i++){
            if(s[i]==s[i-1] && s[i]==s[i-2]){
                continue;

            }
            else{
                str+=s[i];
            }

        }
        return str;
        
    }
};