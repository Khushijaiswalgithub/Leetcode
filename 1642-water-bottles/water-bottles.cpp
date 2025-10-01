class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int n=numBottles;
        int ans=0;
        int d=numExchange;
        int r=0;
        while(n>0){
            ans+=n;
            int x=n+r;
            n=(n+r)/d;
            r=x%d;
            


        }
        return ans;
    }
};