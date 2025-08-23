class Solution {
public:
    bool valid(int row,int col,vector<string>&board,int n){
        int r=row;
        int c=col;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=r;
        col=c;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=c;
        while(row<n && col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,vector<string>&board,int &ans,int n){
        if(col==n){
            ans++;
            return;
        }
        for(int r=0;r<n;r++){
            if(valid(r,col,board,n)){
                board[r][col]='Q';
                solve(col+1,board,ans,n);
                board[r][col]='.';
            }
            
        }
    }
    int totalNQueens(int n) {
        vector<string>board(n);
        int ans=0;
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,board,ans,n);
        return ans;
        
    }
};