class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto it:tokens){
            if(it=="+" ||it=="-"||it=="*"||it=="/"){
                int y=st.top();
                st.pop();
                int x=st.top();
                st.pop();
                if(it=="+") st.push(x+y);
                if(it=="-") st.push(x-y);
                if(it=="*") st.push(x*y);
                if(it=="/") st.push(x/y);
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};