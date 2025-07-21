class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c=0;
                for(auto it:dir){
                    int i_=i+it[0];
                    int j_=j+it[1];
                    if(i_>=0 && i_<n && j_>=0 &&  j_<m && abs(board[i_][j_]) == 1){
                        c++;
                    }
                }
                int x=board[i][j];
                if(x && c<2) board[i][j]=-1;
                else if(x && c>3) board[i][j]=-1;
                else if(!x && c==3) board[i][j]=2;


            }
        }
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == -1) board[i][j] = 0;
            else if (board[i][j] == 2) board[i][j] = 1;
        }
    }
        
    }
};