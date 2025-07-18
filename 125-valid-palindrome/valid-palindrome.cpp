class Solution {
public:
    bool palin(string &str){
        int n=str.size();
        int i=0;
        while(i<n/2){
           if(str[i]!=str[n-i-1]) return false;
           i++;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str="";
        for(auto ch:s){
            if(isalnum(ch)){
            
                str+=tolower(ch);
                
                
            }
        }
        return palin(str);
        
    }
};