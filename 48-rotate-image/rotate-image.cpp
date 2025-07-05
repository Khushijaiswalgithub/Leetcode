class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                grid[j][i]=matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            reverse(grid[i].begin(),grid[i].end());
        }
        matrix=grid;

        
    }
};