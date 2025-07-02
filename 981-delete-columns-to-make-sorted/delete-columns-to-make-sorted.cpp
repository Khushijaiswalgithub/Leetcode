class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        string str="";
        for(int i=0;i<m;i++){
            str+=strs[i];
        }
        int l=str.size();
        int c=0;
        for(int i=0;i<n;i++){
            vector<char>res;
            for(int j=i;j<l;j+=n){
              
              res.push_back(str[j]);
            }
            if(!is_sorted(res.begin(),res.end())){
                c++;
            }

        }
        return c;
        
    }
};