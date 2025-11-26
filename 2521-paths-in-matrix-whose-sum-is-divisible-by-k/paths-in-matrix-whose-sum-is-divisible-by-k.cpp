class Solution {
public:
    int n, m;
    const int MOD = 1e9 + 7;

    int f(int i, int j, int mod, vector<vector<int>>& grid, int k,
          vector<vector<vector<int>>>& dp) {

        if (i >= n || j >= m) return 0;

        mod = (mod + grid[i][j]) % k;

        if (i == n - 1 && j == m - 1)
            return mod == 0;

        if (dp[i][j][mod] != -1)
            return dp[i][j][mod];

        long long down = f(i + 1, j, mod, grid, k, dp);
        long long right = f(i, j + 1, mod, grid, k, dp);

        return dp[i][j][mod] = (down + right) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));

        return f(0, 0, 0, grid, k, dp);
    }
};
