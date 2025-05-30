class Solution {
public:
int n;
    void dfs(vector<int>& edges, int node, vector<int>& dist, vector<bool>& visited) {
    visited[node] = true;
    int v = edges[node];
    if (v != -1 && !visited[v]) {
        dist[v] = 1 + dist[node];
        dfs(edges, v, dist, visited);
    }
}

int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);
    vector<bool> vis1(n, false), vis2(n, false);

    dist1[node1] = 0;
    dist2[node2] = 0;

    dfs(edges, node1, dist1, vis1);
    dfs(edges, node2, dist2, vis2);

    int minNode = -1, minDist = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
            int currMax = max(dist1[i], dist2[i]);
            if (currMax < minDist) {
                minDist = currMax;
                minNode = i;
            }
        }
    }
    return minNode;
}

};