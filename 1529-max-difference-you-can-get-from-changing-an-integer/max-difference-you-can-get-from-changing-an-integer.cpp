class Solution {
public:
    int maxDiff(int num) {
    string s1 = to_string(num);
    string s2 = s1;

    // For max: replace first non-9 digit with 9
    for (char& c : s1) {
        if (c != '9') {
            char ch = c;
            for (char& x : s1) {
                if (x == ch) x = '9';
            }
            break;
        }
    }

    // For min: replace the first digit not 1 (for first place) or not 0 (after)
    if (s2[0] != '1') {
        char ch = s2[0];
        for (char& x : s2) {
            if (x == ch) x = '1';
        }
    } else {
        for (int i = 1; i < s2.size(); i++) {
            if (s2[i] != '0' && s2[i] != s2[0]) {
                char ch = s2[i];
                for (char& x : s2) {
                    if (x == ch) x = '0';
                }
                break;
            }
        }
    }

    return stoi(s1) - stoi(s2);
}

};