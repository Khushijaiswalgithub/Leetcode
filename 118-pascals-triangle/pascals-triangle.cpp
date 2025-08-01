class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>ans;
        ans.push_back({1});
        if(n==1) return ans;
        ans.push_back({1,1});
        if(n==2) return ans;
        n-=2;
        while(n--){
            vector<int>res;
            res.push_back(1);
            vector<int>last;
            last=ans.back();
            for(int i=0;i<last.size()-1;i++){
                res.push_back(last[i]+last[i+1]);
            }
            res.push_back(1);
            ans.push_back(res);
        }
        return ans;
        
    }
};