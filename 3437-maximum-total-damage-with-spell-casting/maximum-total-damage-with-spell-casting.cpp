class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> sum;
    for (int x : power) sum[x] += x; 

    vector<long long> keys;
    for (auto& [k, v] : sum) keys.push_back(k);
    sort(keys.begin(), keys.end());

    int n = keys.size();
    vector<long long> dp(n, 0);

    for (int i = 0; i < n; i++) {
        long long take = sum[keys[i]];
        int j = i - 1;
        while (j >= 0 && keys[i] - keys[j] <= 2) j--; 
        if (j >= 0) take += dp[j];

        dp[i] = max((i > 0 ? dp[i-1] : 0LL), take);
    }
    return dp[n-1];
    }
};