class Solution {
public:
typedef long long ll;
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum=0;
        int c=0;
        int mini=INT_MAX;

        for(ll num:nums){
            if((num^k)>num){
                c++;
                sum+=num^k;
            }
            else{
                sum+=num;
            }
            mini=min((long long)mini,abs(num-(num^k)));
        }
        if(c%2==0){
            return sum;
        }
        return sum-mini;
    }
};