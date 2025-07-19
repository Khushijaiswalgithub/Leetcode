class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string>mp;
        sort(folder.begin(),folder.end());
        for(auto it:folder){
            if(mp.empty()){
                mp.insert(it);
            }
            else{
                bool f=false;
                for(int i=0;i<it.size();i++){
                    if(it[i]=='/' && mp.find(it.substr(0,i))!=mp.end()){
                       f=true;
                    }
                }
                if(!f){
                    mp.insert(it);
                }
            }
        }
        vector<string>ans(mp.begin(),mp.end());
        return ans;
        
    }
};