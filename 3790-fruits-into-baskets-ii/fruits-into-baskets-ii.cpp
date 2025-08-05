class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int rem=0;
        vector<int>vis(n,0);
        
        for(int i=0;i<n;i++){
            int f=false;
            for(int j=0;j<n;j++){
                
                if(vis[j]!=1 && fruits[i]<=baskets[j]){
                    vis[j]=1;
                    f=true;
                    break;
                }
            }
            if(!f){
                rem++;

            }

        }
        return rem;
        
    }
};