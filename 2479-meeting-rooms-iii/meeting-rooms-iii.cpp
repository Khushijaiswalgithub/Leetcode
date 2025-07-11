class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>avail(n,0);
        vector<int>used(n,0);
        sort(meetings.begin(),meetings.end());
        for(auto it:meetings){
            int s=it[0];
            int e=it[1];
            int d=e-s;
            bool f=false;
            long long earlytime=LLONG_MAX;
            int earlyroom=0;
            for(int i=0;i<n;i++){
                if(avail[i]<=s){
                    avail[i]=e;
                    used[i]++;
                    f=true;
                    break;
                }
                if(avail[i]<earlytime){
                    earlytime=avail[i];
                    earlyroom=i;

                }
            }
            if(!f){
                avail[earlyroom]+=d;
                used[earlyroom]++;
            }
        }
        int result=-1;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(maxi<used[i]){
            maxi=used[i];
            result=i;
            }
        }
        return result;
    }
};