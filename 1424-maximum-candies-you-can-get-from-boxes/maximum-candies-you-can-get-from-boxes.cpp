class Solution {
public:
    int f(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,int box, unordered_set<int>&vis,unordered_set<int>&found){
        if(vis.count(box)){
            return 0;
        }
        
        if(status[box]==0 ){
            found.insert(box);
            return 0;
        }
        vis.insert(box);
        int t=candies[box];
        for(auto it:containedBoxes[box]){
            t+=f(status, candies,keys,containedBoxes,it,vis,found);

        }
        for(auto it:keys[box]){
            status[it]=1;
            if(found.count(it)){
                t+=f(status, candies,keys,containedBoxes,it,vis,found);


            }
        }
        return t;


    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int c=0;
        unordered_set<int>vis;
        unordered_set<int>found;
        for(int i=0;i<initialBoxes.size();i++){
            c+=f(status, candies,keys,containedBoxes,initialBoxes[i],vis,found);
        }
        return c;
        
    }
};