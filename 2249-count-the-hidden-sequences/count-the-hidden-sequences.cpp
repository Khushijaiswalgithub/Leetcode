class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int cnt=0;
        int mini=0;
        int maxi=0;
        for(auto d:differences){
            cnt+=d;
            mini=min(cnt,mini);
            maxi=max(cnt,maxi);
            if(((upper-maxi)-(lower-mini)+1)<=0){
                return 0;
            }
        }
        return (upper-maxi)-(lower-mini)+1;
    }
};