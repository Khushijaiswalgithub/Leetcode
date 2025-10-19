class Solution {
public:
    void rotateString(string &s, int b) {
    int n = s.size();
    b %= n; // handle cases where b > n
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + b);
    reverse(s.begin() + b, s.end());
}

string findLexSmallestString(string s, int a, int b) {
    queue<string> q;
    unordered_set<string> vis;
    q.push(s);
    vis.insert(s);
    string ans = s;

    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        ans = min(ans, cur);

        // Operation 1: Add 'a' to digits at odd indices
        string t = cur;
        for (int i = 1; i < (int)t.size(); i += 2) {
            t[i] = ((t[i] - '0' + a) % 10) + '0';
        }
        if (!vis.count(t)) {
            vis.insert(t);
            q.push(t);
        }

        // Operation 2: Rotate the string
        string r = cur;
        rotateString(r, b);
        if (!vis.count(r)) {
            vis.insert(r);
            q.push(r);
        }
    }
    return ans;
}
};