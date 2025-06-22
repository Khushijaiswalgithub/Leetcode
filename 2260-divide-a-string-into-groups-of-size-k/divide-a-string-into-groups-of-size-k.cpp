class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    vector<string> st;
    int n = s.size();
    for (int i = 0; i < n; i += k) {
        string str;
        if (i + k > n) {
            str = string(s.begin() + i, s.end());
        } else {
            str = string(s.begin() + i, s.begin() + i + k);
        }

        while (str.size() < k) {
            str.push_back(fill);
        }

        st.push_back(str);
    }
    return st;
}

};