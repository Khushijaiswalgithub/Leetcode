class Solution {
public:
int n;
    bool isvalid(string str){
        if(str[0]=='0') return false;
        int num=stoi(str);
        if(num>255) return false;
        return true;
    }
    void solve(int ind,int p,string curr,string &s,vector<string>&res){
        if(ind==n && p==4){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        if(ind+1<=n ){
            solve(ind+1,p+1,curr+s.substr(ind,1)+".",s,res);
        }
        if(ind+2<=n && isvalid(s.substr(ind,2)) ){
            solve(ind+2,p+1,curr+s.substr(ind,2)+".",s,res);
        }
        if(ind+3<=n && isvalid(s.substr(ind,3))){
            solve(ind+3,p+1,curr+s.substr(ind,3)+".",s,res);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        n=s.size();
        if(n>12) return {};
        vector<string>res;
        string curr="";
        int p=0;
        solve(0,p,curr,s,res);
        return res;
    }
};