class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0; 
    int ans = 0;

    for (string &row : bank) {
        int ones = count(row.begin(), row.end(), '1'); 
        if (ones > 0) {
            ans += prev * ones; 
            prev = ones; 
        }
    }

    return ans;
    }
};