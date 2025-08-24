class Solution {
public:
    bool f(int ind,vector<vector<char>>& board, string word,vector<vector<int>>&vis,int n,int m,int r,int c){
        if(board[r][c]!=word[ind] ) return false;
        if (ind== word.size()-1) return true;
        
        vis[r][c]=1;
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=1 ){
                
                
                if(f(ind+1,board,word,vis,n,m,nr,nc)){
                    vis[r][c] = 0;   
                    return true;
                }
            }

        }
        vis[r][c]=0;
        return false;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    
                    
                    if( f(0,board,word,vis,n,m,i,j)){
                        return true;

                    }
                }
            }
        }
        return false;
        
    }
};