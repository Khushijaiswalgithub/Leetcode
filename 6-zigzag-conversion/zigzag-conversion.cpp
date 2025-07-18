class Solution {
public:
    string convert(string s, int numRows) {
    if (numRows == 1 || s.size() <= numRows) return s;

    vector<string> res(min(numRows, int(s.length())));
    int n = s.size();
    int i = 0;

    while (i < n) {
        // Go vertically down
        for (int ind = 0; ind < numRows && i < n; ind++) {
            res[ind] += s[i];
            i++;
        }

        
        for (int ind = numRows - 2; ind > 0 && i < n; ind--) {
            res[ind] += s[i];
            i++;
        }
    }

    string ans = "";
    for (auto str : res) {
        ans += str;
    }

    return ans;
}

};