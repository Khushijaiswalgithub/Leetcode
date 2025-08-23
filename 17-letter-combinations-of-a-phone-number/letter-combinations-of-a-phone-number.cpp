#include <string>
class Solution {
public:
    void f(int ind,vector<string> &ans,string &str,string digits,unordered_map<char,string> mp){
        if(ind==digits.size()){
             ans.push_back(str);
             return;
           
        }
        char ch=digits[ind];
        string s=mp[ch];
        for(int i=0;i<4;i++){
            if(i>=s.size()) continue;
            str.push_back(s[i]);
            f(ind+1,ans,str,digits,mp);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char,string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>ans;
        string str="";
        f(0,ans,str,digits,mp);
        return ans;
        

        
        
    }
};