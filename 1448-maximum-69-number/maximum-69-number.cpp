class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        string ans="";
        bool f=true;
        for(auto it:s){
            if(f && it=='6'){
                ans+='9';
                f=false;
            }
            else{
            ans+=it;
            }
            
        }
        return stoi(ans);
        
    }
};