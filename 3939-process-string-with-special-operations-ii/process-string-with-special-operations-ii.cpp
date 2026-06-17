class Solution {
public:
    char processStr(string s, long long k) {
        using int64 = long long;

        // Compute final length
        int64 len = 0;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                len++;
            } else if (c == '*') {
                if (len > 0) len--;
            } else if (c == '#') {
                len *= 2;
            } else if (c == '%') {
                // length unchanged
            }
        }

        if (k >= len) return '.';

        // Work backwards
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                if (k == len - 1)
                    return c;
                len--;
            }
            else if (c == '*') {
                len++;
            }
            else if (c == '#') {
                long long half = len / 2;
                if (k >= half)
                    k -= half;
                len = half;
            }
            else if (c == '%') {
                k = len - 1 - k;
            }
        }

        return '.';
    }
};