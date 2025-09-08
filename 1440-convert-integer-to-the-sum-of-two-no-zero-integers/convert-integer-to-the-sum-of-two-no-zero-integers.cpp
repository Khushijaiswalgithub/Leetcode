class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a=n;
        int b=0;
        int p=1;
        while(n>1){
            int t=1;
            if(n%10==1){
                t=2;
            }
            a-=t*p;
            b+=t*p;
            n=(n-t)/10;
            p*=10;
        }
        return {a,b};
        
    }
};