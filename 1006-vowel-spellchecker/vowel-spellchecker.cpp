class Solution {
public:
    string toLower(string s) {
    for (auto &ch : s) ch = tolower(ch);
    return s;
}

string devowel(string s) {
    for (auto &ch : s) {
        char c = tolower(ch);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ch = '*';
        } else {
            ch = tolower(ch);
        }
    }
    return s;
}

vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
    unordered_set<string> exact(wordlist.begin(), wordlist.end());
    unordered_map<string,string> caseInsensitive;
    unordered_map<string,string> vowelInsensitive;

    
    for (auto &word : wordlist) {
        string lower = toLower(word);
        string noVowels = devowel(word);

        
        if (!caseInsensitive.count(lower)) {
            caseInsensitive[lower] = word;
        }
        if (!vowelInsensitive.count(noVowels)) {
            vowelInsensitive[noVowels] = word;
        }
    }

    vector<string> ans;
    for (auto &q : queries) {
        if (exact.count(q)) {
            ans.push_back(q); 
        } 
        else {
            string lower = toLower(q);
            string noVowels = devowel(q);

            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
            } 
            else if (vowelInsensitive.count(noVowels)) {
                ans.push_back(vowelInsensitive[noVowels]);
            } 
            else {
                ans.push_back("");
            }
        }
    }
    return ans;
}

};