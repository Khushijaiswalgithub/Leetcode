class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        int l=0;
        int r=0;
        int maxi=0;
        while(r<n){
            mp[fruits[r]]++;
            
            while(mp.size()>2){
                
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size()<=2){
                maxi=max(maxi,r-l+1);
            }
            r++;

        }
        return maxi;
    }
};