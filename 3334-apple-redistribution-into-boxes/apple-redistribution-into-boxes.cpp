class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n=apple.size();
        int m=capacity.size();
        int sum=0;
        for(auto it:apple){
            sum+=it;
        }
        sort(capacity.rbegin(),capacity.rend());
        int cap=0;
        int ans=0;
        if(cap>=sum)return ans;
        for(auto it:capacity){
            cap+=it;
            ans++;
            if(cap>=sum){
                break;
            }


        }
        return ans;
    }
};