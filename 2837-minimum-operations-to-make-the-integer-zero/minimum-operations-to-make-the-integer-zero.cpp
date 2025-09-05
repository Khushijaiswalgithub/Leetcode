class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        
        for(int t=0;t<=36;t++){
            long long num=(long long)num1-(long long)t*num2;
            if(num<0) return -1;
            if(__builtin_popcountll(num)<=t && t<=num){
                return t;
            }
            
        }
        return -1;

        
    }
};