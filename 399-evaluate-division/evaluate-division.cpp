class Solution {
public:
    void dfs(string src,string dst,unordered_set<string>&vis,double &ans,double pro,unordered_map<string,vector<pair<string,double>>>adj){
        if(vis.find(src)!=vis.end()) return;
        vis.insert(src);
        if(src==dst){
            ans=pro;
            return;

        }
        for(auto it:adj[src]){
            string v=it.first;
            double val=it.second;
            dfs(v,dst,vis,ans,pro*val,adj);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            adj[u].push_back({v,values[i]});
            adj[v].push_back({u,1.0/values[i]});
        }
        vector<double>res;
        for(auto it:queries){
            string src=it[0];
            string dst=it[1];
            double ans=-1.0;
            double pro=1.0;
            if(adj.find(src)!=adj.end()){
            unordered_set<string>vis;

            dfs(src,dst,vis,ans,pro,adj);
            }
            res.push_back(ans);
        }
        return res;
    }
};