class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int>f(n+1);
        for(int i=0;i<n;i++){
            if(citations[i]>=n){
              f[n]++;
            }
            else{
                f[citations[i]]++;
            }

        }
        int hind=n;
        int num=f[n];
        while(num<hind){
            hind--;
            num+=f[hind];
        }
        return hind;
    }
};