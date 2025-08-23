class Solution {
public:
    void f(int ind,vector<vector<int>> &ans,vector<int> &num,int n,int k){
        if(ind==k){
             ans.push_back(num);
             return;
           
        }
        
        for(int i=1;i<=n;i++){
            if(!num.empty() && num.back()>=i) continue;
            num.push_back(i);
            f(ind+1,ans,num,n,k);
            num.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int> num;
        f(0,ans,num,n,k);
        return ans;
        
    }
};