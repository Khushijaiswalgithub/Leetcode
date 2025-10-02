class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int n=numBottles;
        int d=numExchange;
        int r=0;
        int ans=0;
        while(n>0){
            ans=ans+n;
            r+=n;
            n=0;
            while(r>=d){
                n++;
                r-=d;
                d++;


            } 
            
        }
        return ans;
        
    }
};