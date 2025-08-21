class Solution {
public:
    int f(vector<int>&vec){
        int c=0;
        int s=0;
        for(auto it:vec){
            if(it==0){
                c=0;
            }
            else{
                c++;
            }
            s+=c;
        }
        return s;
    }
    int numSubmat(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       int res=0;
       for(int s=0;s<n;s++){
        vector<int>vec(m,1);
        for(int e=s;e<n;e++){
            for(int c=0;c<m;c++){
                vec[c]=vec[c] & mat[e][c];
            }
            res+=f(vec);
            
        }
       }
       return res;
    
    }
};