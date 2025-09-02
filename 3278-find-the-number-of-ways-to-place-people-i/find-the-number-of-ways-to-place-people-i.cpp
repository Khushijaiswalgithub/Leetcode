class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        for(int i=0;i<n;i++){
            points[i][1]=-points[i][1];
        }
        sort(points.begin(),points.end());
        int ans=0;
        for(int i=0;i<n;i++){
            int y=-points[i][1];
            int ymax=-1e9;
            for(int j=i+1;j<n;j++){
                int y1=-points[j][1];
                if(y1>ymax && y1<=y){
                    ans++;
                    ymax=max(y1,ymax);
                }
            }
        }
        return ans;
        
    }
};