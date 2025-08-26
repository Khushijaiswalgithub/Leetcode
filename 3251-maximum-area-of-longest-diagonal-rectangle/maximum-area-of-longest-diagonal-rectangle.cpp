class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxi=0;
        long long md=-1;
        for(auto it:dimensions){
            int l=it[0];
            int w=it[1];
            long long d= 1LL * l * l + 1LL * w * w;
            if (d > md) {
            md = d;
            maxi = l*w;
        } else if (d == md) {
            maxi= max(maxi,l*w);
        }

        }
        return maxi;
    }
};