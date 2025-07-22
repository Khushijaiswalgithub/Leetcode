class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char &ch:s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char x=st.top();
                st.pop();
                if((x=='(' && ch!=')') || (x=='{' && ch!='}') || (x=='[' && ch!=']')){
                    return false;

                }

            }
            
        }
        if(!st.empty()){
             return false;
        }
        return true;
        
        
    }
};