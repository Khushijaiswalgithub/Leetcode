class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        set<int>st;
        unordered_map<int,int>mp;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                st.insert(i);
            }
            else{
                ans[i]=-1;
                int lake=rains[i];
                if(mp.count(lake)){
                    auto it=st.lower_bound(mp[lake]);
                    if(it==st.end()){
                        return {};
                    }
                    int day=*it;
                    ans[day]=lake;
                    st.erase(day);
                }
                mp[lake]=i;
            }
        }
        return ans;
        
    }
};