class Solution {
public:
    vector<char>choice={'A','C','G','T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>valid(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
            string s=q.front().first;
            int step=q.front().second;
            q.pop();
            if(s==endGene) return step;
            int n=s.size();
            for(int i=0;i<n;i++){
                char ori=s[i];
                for(int j=0;j<4;j++){
                    if(s[i]==choice[j]) continue;
                    s[i]=choice[j];
                    if(valid.find(s)!=valid.end()){
                        q.push({s,step+1});
                        valid.erase(s);
                    }
                }
                s[i]=ori;

            }
        }
        return -1;
        
    }
};