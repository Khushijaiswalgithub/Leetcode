class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            
           std::string next = "";
            for(auto c:word){
               char x = (c == 'z') ? 'a' : c + 1;
                next+=x;
            }
            word+=next;
        }
        return word[k-1];
    }
};