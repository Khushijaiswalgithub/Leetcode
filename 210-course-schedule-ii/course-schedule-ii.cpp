class Solution {
public:
vector<int> toposort(int n,vector<int>adj[]){
     vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;

            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            topo.push_back(x);
            for(auto it:adj[x]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);

            }
        }
        if(topo.size()==n){
             reverse(topo.begin(),topo.end());
             return topo;
        }
        else{
            return {};
        }
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        return toposort(numCourses,adj);
    }
};