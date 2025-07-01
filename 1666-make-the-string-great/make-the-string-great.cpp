class Solution {
public:
    string makeGood(string s) {
        int n=s.size();
        string res="";
        for(char ch:s){
            if(!res.empty() && abs(res.back()-ch)==32){
                res.pop_back();
            }
            else{
                res+=ch;
            }

        }
        return res;
    }
};