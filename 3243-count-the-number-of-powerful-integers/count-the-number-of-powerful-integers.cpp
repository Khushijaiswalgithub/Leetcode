class Solution {
public:
    long long solve(string str,string s,int limit){
        if(str.length()<s.length()) return 0;
        int rlength=str.size()-s.size();
        string lstr=str.substr(rlength);
        long long c=0;
        for(int i=0;i<rlength;i++){
            int d=str[i]-'0';
            if(d<=limit){
                c+=d*pow(limit+1,rlength-i-1);
            }
            else{
                c+=pow(limit+1,rlength-i);
                return c;
            }

        }
        if(lstr>=s){
            return c+1;
        }
        return c;
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string sstr=to_string(start-1);
        string fstr=to_string(finish);
        return solve(fstr,s,limit) - solve(sstr,s,limit);
        
    }
};