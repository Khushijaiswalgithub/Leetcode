class Solution {
public:
    int largestVariance(string s) {
    int maxi = 0;
    vector<int> freq(26, 0);

    for (char ch : s) {
        freq[ch - 'a']++;
    }

    for (char f = 'a'; f <= 'z'; f++) {
        for (char g = 'a'; g <= 'z'; g++) {
            if (f == g || freq[f - 'a'] == 0 || freq[g - 'a'] == 0) continue;

            for (int pass = 0; pass < 2; pass++) {
                int fCount = 0, gCount = 0;
                bool canExtendPrevG = false;

                for (char ch : s) {
                    if (ch != f && ch != g) continue;

                    if (ch == f) fCount++;
                    if (ch == g) gCount++;

                    if (gCount > 0)
                        maxi = max(maxi, fCount - gCount);
                    else if (canExtendPrevG)
                        maxi = max(maxi, fCount - 1);

                    if (gCount > fCount) {
                        fCount = 0;
                        gCount = 0;
                        canExtendPrevG = true;
                    }
                }

            
                // reverse(s.begin(), s.end());
            }
        }
    }

    return maxi;
}

};