class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int totalcost=0;
        for(int i=0;i<n;i++){
            totalcost+=cost[i];
            total+=gas[i];

        }
        if(totalcost>total) return -1;
        int res=0;
        int t=0;
        for(int i=0;i<n;i++){
            t+=gas[i]-cost[i];
            if(t<0){
                res=(i+1)%n;
                t=0;
            }
        }
        return res;
    }
};