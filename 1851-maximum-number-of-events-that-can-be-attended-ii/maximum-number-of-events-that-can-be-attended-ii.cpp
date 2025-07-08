class Solution {
public:
    int n;
    vector<vector<int>> t;

    int solve(vector<vector<int>>& events, int i, int k) {
        if (k == 0 || i == n)
            return 0;

        if (t[i][k] != -1)
            return t[i][k];

        // Find the next non-overlapping event using binary search
        int nextIdx = upper_bound(events.begin(), events.end(), events[i][1],
            [](int val, const vector<int>& e) {
                return val < e[0]; // e[0] = start of event
            }) - events.begin();

        // Two choices: take or skip
        int take = events[i][2] + solve(events, nextIdx, k - 1);
        int skip = solve(events, i + 1, k);

        return t[i][k] = max(take, skip);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); // sort by start time
        n = events.size();
        t.resize(n + 1, vector<int>(k + 1, -1));
        return solve(events, 0, k);
    }
};
