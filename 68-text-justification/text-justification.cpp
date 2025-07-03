class Solution {
public:
    int maxw;
    int n;

    string f(int i, int j, vector<string>& words, int eachs, int extras, bool lastLine) {
        string line = "";
        int wordsInLine = j - i;

        for (int k = i; k < j; ++k) {
            line += words[k];

            if (k == j - 1) break; 

            if (lastLine) {
                line += " ";  
            } else {
                int spacesToAdd = eachs + (extras > 0 ? 1 : 0);
                line += string(spacesToAdd, ' ');
                if (extras > 0) extras--;
            }
        }

        while (line.size() < maxw) {
            line += " ";
        }

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        maxw = maxWidth;
        n = words.size();
        vector<string> res;
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineLen = words[i].size();

            while (j < n && lineLen + words[j].size() + (j - i) <= maxw) {
                lineLen += words[j].size();
                j++;
            }

            int wordCount = j - i;
            int spaceCount = wordCount - 1;
            int remSpace = maxw - lineLen;

            int eachs = (spaceCount > 0) ? remSpace / spaceCount : 0;
            int extras = (spaceCount > 0) ? remSpace % spaceCount : 0;

            bool lastLine = (j == n || wordCount == 1);
            string line = f(i, j, words, eachs, extras, lastLine);

            res.push_back(line);
            i = j;
        }

        return res;
    }
};
