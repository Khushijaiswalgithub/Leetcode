class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int c=0;
        
        int i=n-1;
        while(s[i]==' ') i--;
        while(i>=0 && s[i]!=' '){
            c++;
            i--;
        }
        return c;
    }
};