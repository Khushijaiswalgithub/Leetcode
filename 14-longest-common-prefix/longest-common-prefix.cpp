class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n=strs.size();
        sort(strs.begin(),strs.end());
        string s1=strs[0];
        string s2=strs[n-1];
        int ind=0;
        while(ind<s1.size()){
            if(s1[ind]==s2[ind]){
                ind++;
            }
            else{
                break;
            }

        }
        return ind==0?"":s1.substr(0,ind);
    }
};