class Solution {
public:
    void generate(int ind,int o,int c,vector<string> &ds,string &str,int n){
        if(ind==2*n){
            if(o==c)ds.push_back(str);
            return;

        }
        if(o<n){
            o++;
            str.push_back('(');
            generate(ind+1,o,c,ds,str,n);
            o--;
            str.pop_back();
        }
        if(c<o && c<n){
            c++;
            str.push_back(')');
            generate(ind+1,o,c,ds,str,n);
            c--;
            str.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        int ind=0,c=0,o=0;
        vector<string> ds;
        string str="";
        generate(ind,o,c,ds,str,n);
        return ds;


        
    }
};