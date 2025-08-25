class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i+j].push_back(mat[i][j]);
            }
        }
        int flip=1;
        vector<int>ans;
        for(auto it:mp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            for(auto x:it.second){
                ans.push_back(x);
            }
            flip=!flip;

        }
        return ans;
        
    }
};