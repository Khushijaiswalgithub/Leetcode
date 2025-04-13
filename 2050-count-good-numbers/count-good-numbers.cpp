class Solution {
public:
    const int mod=1000000007;
    long long pow(long long base,long long n,long long &ans){
        
        if(n==0) return ans;
        if(n%2==0){
            base=(base*base)%mod;
            n=n/2;

        }
        else{
            ans=(ans*base)%mod;
            n=n-1;
        }
        return pow(base,n,ans);
        
    
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long ans1=1;
        long long ans2=1;
        
        long long e=pow(5,even,ans1);
        long long o=pow(4,odd,ans2);
        return (e*o)%mod;



    }
};