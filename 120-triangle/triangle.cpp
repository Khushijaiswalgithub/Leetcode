class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<int> dp(m);
    for(int j = 0; j < m; j++) {
        dp[j] = triangle[m-1][j];
    }
    for(int i = m-2; i >= 0; i--) {
        for(int j = 0; j <= i; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
    }
    
    return dp[0];
}

};