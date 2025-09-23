class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>n1;
        vector<int>n2;
        int num=0;
        int n=version1.size();
        int m=version2.size();
        for(int i=0;i<=n;i++){
            if(i==n  || version1[i]=='.'){
                n1.push_back(num);
                num=0;
            }
            else{
                num=num*10+(version1[i]-'0');
            }
        }
        
        num=0;
        for(int i=0;i<=m;i++){
            if(i==m || version2[i]=='.'){
                n2.push_back(num);
                num=0;
            }
            else{
                num=num*10+(version2[i]-'0');
            }
        }
        n=n1.size();
        m=n2.size();
        
        for(int i=0;i<min(n,m);i++){
            if(n1[i]<n2[i]) return -1;
            if(n1[i]>n2[i]) return 1;
        }
        if(n>m){
            for(int i=m;i<n;i++){
                if(n1[i]!=0) return 1;
            }
        }
        if(n<m){
            for(int i=n;i<m;i++){
                if(n2[i]!=0) return -1;
            }
        }
        return 0;
        
    }
};