class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
    int m = needle.size();

    if (m == 0) return 0; 

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        for (; j < m; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }
        if (j == m) return i; 
    }
    return -1; 
        
    }
};