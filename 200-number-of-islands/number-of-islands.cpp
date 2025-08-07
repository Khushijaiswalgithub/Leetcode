class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,1},{0,-1},{1,0}};
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>>&vis){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(auto d:dir){
            int nr=r+d[0];
            int nc=c+d[1];
            if(nc>=0 && nr>=0 && nc<m && nr<n && grid[nr][nc]=='1' && vis[nr][nc]!=1){
                dfs(nr,nc,grid,vis);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
       vector<vector<int>>vis(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]=='1'){
            dfs(i,j,grid,vis);
            c++;
            }

        }
       }
       return c;
    }
};