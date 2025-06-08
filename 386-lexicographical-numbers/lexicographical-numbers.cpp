class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>num;
        int curr=1;
        for(int i=1;i<=n;i++){
            num.push_back(curr);
            if(curr*10<=n){
              curr=curr*10;
            }
            else{
                while(curr%10==9 || curr>=n){
                    curr=curr/10;
                }
                curr++;
            }
        }
        return num;
    }
};