class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        vector<bool> hasSecret(n, false);
        hasSecret[0] = hasSecret[firstPerson] = true;

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            unordered_set<int> people;
            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                people.insert(meetings[j][0]);
                people.insert(meetings[j][1]);
                j++;
            }

            parent.clear();
            parent.resize(n);
            for (int p : people) parent[p] = p;
            for (int k = i; k < j; k++) {
                unite(meetings[k][0], meetings[k][1]);
            }
            unordered_map<int, bool> componentHasSecret;
            for (int p : people) {
                int root = find(p);
                if (hasSecret[p]) componentHasSecret[root] = true;
            }
            for (int p : people) {
                if (componentHasSecret[find(p)]) {
                    hasSecret[p] = true;
                }
            }

            i = j;
        }

        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (hasSecret[i]) result.push_back(i);
        }
        return result;
    }
};