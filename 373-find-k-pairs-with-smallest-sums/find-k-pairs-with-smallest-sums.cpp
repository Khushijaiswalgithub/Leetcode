class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
       int sum=nums1[0]+nums2[0];
       pq.push({sum,0,0});
       set<pair<int,int>>vis;
       int n=nums1.size();
       int m=nums2.size();
       vis.insert({0,0});
       
       vector<vector<int>>ans;
       while(k>0 && !pq.empty()){
        vector<int>x=pq.top();
        pq.pop();
        int i=x[1];
        int j=x[2];
        ans.push_back({nums1[i],nums2[j]});
        k--;
        if( j+1<m && vis.find({i,j+1})==vis.end()){
            pq.push({nums1[i]+nums2[j+1],i,j+1});
            vis.insert({i,j+1});
            
        }
        if( i+1<n && vis.find({i+1,j})==vis.end()){
            pq.push({nums1[i+1]+nums2[j],i+1,j});
            vis.insert({i+1,j});
        
        }

       }
      return ans;
       
    }
};