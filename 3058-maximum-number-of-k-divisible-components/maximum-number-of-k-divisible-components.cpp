class Solution {
public:
    int cnt = 0;
    int k;
    vector<vector<int>> adj;

    long long dfs(int node, int parent, vector<int>& values) {
        long long sum = values[node];

        for (int nei : adj[node]) {
            if (nei == parent) continue;

            long long childSum = dfs(nei, node, values);

            // If child subtree sum is divisible by k -> cut edge
            if (childSum % k == 0) {
                cnt++;
            } else {
                sum += childSum;  // else merge into parent
            }
        }

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        adj.assign(n, {});

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        long long total = dfs(0, -1, values);

        // root component also valid (because sum of all values divisible by k)
        if (total % k == 0) cnt++;

        return cnt;
    }
};
