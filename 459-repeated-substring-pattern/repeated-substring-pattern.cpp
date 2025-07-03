class Solution {
public:
    bool f(int ind, int l, int n, string& s, string& str) {
    if (ind == n) return true;
    if (ind + l > n) return false;

    string x = s.substr(ind, l);
    if (x == str) {
        return f(ind + l, l, n, s, str);
    }

    return false;
}

bool repeatedSubstringPattern(string s) {
    int n = s.size();
    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) {
            string pattern = s.substr(0, len);
            if (f(len, len, n, s, pattern)) {
                return true;
            }
        }
    }
    return false;
}

};