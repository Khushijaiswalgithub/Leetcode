class Solution {
public:
unordered_map<string,bool>mp;
   bool isvalid(string word,unordered_set<string>&st){
    if(mp.find(word)!=mp.end()) return mp[word];
      for(int i=0;i<word.size();i++){
        string pre=word.substr(0,i+1);
        string suf=word.substr(i+1);
        if((st.find(pre)!=st.end() && st.find(suf)!=st.end()) || (st.find(pre)!=st.end() && isvalid(suf,st))){
            return mp[word]=true;
        }
      }
      return mp[word]=false;
   }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        mp.clear();
        unordered_set<string>st(words.begin(),words.end());
        vector<string>res;
        for(auto word:words){
          if(isvalid(word,st)){
            res.push_back(word);
          }
        }
        return res;
        
    }
};