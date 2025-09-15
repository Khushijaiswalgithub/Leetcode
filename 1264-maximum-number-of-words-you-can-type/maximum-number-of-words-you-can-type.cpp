class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> vec(26, false);
        for (char c : brokenLetters) {
           vec[c - 'a'] = true;
        }
    
    int count = 0;
    stringstream ss(text);
    string word;
    
    while (ss >> word) {
        bool ok = true;
        for (char c : word) {
            if (vec[c - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    }
    
    return count;
        

        
    }
};