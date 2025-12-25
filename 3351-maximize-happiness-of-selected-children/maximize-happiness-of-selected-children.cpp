class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long ans=0;
        int c=0;
        for(auto it:happiness){
            if(it-c<0 || k<=0) break;
            ans+=it-c;
            c++;
            k--;



        }
        return ans;
    }
};