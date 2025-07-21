class Solution {
public:
    bool check(int sr, int er, int sc, int ec, vector<vector<char>>& board) {
    set<char> st;
    for (int i = sr; i <= er; i++) {
        for (int j = sc; j <= ec; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            if (st.find(ch) != st.end()) return false;
            st.insert(ch);
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    
    for (int i = 0; i < 9; i++) {
        set<char> st;
        for (int j = 0; j < 9; j++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            if (st.find(ch) != st.end()) return false;
            st.insert(ch);
        }
    }

    
    for (int j = 0; j < 9; j++) {
        set<char> st;
        for (int i = 0; i < 9; i++) {
            char ch = board[i][j];
            if (ch == '.') continue;
            if (st.find(ch) != st.end()) return false;
            st.insert(ch);
        }
    }

    
    for (int sr = 0; sr < 9; sr += 3) {
        for (int sc = 0; sc < 9; sc += 3) {
            if (!check(sr, sr + 2, sc, sc + 2, board)) return false;
        }
    }

    return true;
}

};