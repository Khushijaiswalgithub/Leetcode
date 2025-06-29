class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>st;
        for(auto it:sentence){
            if(it>='a' && it<='z'){
                st.insert(it);
            }
        }
        if(st.size()==26){
            return true;
        }
        return false;
        
    }
};