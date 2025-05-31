class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flatten(n * n + 1, -1);

        // Flatten the board in Boustrophedon order
        int idx = 1;
        bool leftToRight = true;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    flatten[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    flatten[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        // BFS
        queue<pair<int, int>> q; // {position, moves}
        vector<bool> visited(n * n + 1, false);
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [pos, moves] = q.front();
            q.pop();

            if (pos == n * n) return moves;

            for (int i = 1; i <= 6 && pos + i <= n * n; ++i) {
                int next = pos + i;
                if (flatten[next] != -1) {
                    next = flatten[next];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    
        
    }
};