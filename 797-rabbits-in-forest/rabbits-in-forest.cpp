class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>mp;
        int n=answers.size();
        for(int i=0;i<n;i++){
            mp[answers[i]]++;

        }
        int ans=0;
        for(auto it:mp){
            if(it.second<=it.first+1){
                ans+=it.first+1;
            }
            else{
                int x=it.second/(it.first+1);
                if((it.second%(it.first+1))>0){
                    x++;

                }
                ans+=x*(it.first+1);
            }
        }
        return ans;
        
    }
};