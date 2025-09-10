class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

    vector<unordered_set<int>> known(m + 1);
    for (int i = 0; i < m; i++) {
        for (int lang : languages[i]) {
            known[i + 1].insert(lang); 
        }
    }

    unordered_set<int> candidates;
    for (auto &f : friendships) {
        int u = f[0], v = f[1];
        bool com = false;
        for (int lang : known[u]) {
            if (known[v].count(lang)) {
                com = true;
                break;
            }
        }
        if (!com) {
            candidates.insert(u);
            candidates.insert(v);
        }
    }

    if (candidates.empty()) return 0; 
    int ans = INT_MAX;
    for (int lang = 1; lang <= n; lang++) {
        int cnt = 0;
        for (int user : candidates) {
            if (!known[user].count(lang)) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }

    return ans;
        
    }
};