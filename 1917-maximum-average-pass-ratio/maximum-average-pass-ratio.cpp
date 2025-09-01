class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>>pq;
        int n=classes.size();
        for(int i=0;i<n;i++){
            double r=(double)classes[i][0]/classes[i][1];
            double ur=(double)(classes[i][0]+1)/(classes[i][1]+1);
            double delta=ur-r;
            pq.push({delta,i});
        }
        while(extraStudents--){
            int idx=pq.top().second;
            double d=pq.top().first;
            pq.pop();
            classes[idx][0]++;
            classes[idx][1]++;
            double r=(double)classes[idx][0]/classes[idx][1];

            double ur=(double)(classes[idx][0]+1)/(classes[idx][1]+1);
            double delta=ur-r;
            pq.push({delta,idx});
            
            
        }
        double res=0.0;
        for(int i=0;i<n;i++){
            res+=(double)classes[i][0]/classes[i][1];
        }
        return res/n;
        
    }
};