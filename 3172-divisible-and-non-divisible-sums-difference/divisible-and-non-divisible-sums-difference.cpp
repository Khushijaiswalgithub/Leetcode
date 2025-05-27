class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num2=0;
        for(int i=m;i<=n;i=i+m){
            num2+=i;

        }
        int t=n*(n+1)/2;
        int num1=t-num2;
        return num1-num2;
    }
};