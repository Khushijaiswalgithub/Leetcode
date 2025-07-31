class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>res;
        set<int>curr;
        for(auto num:arr){
            set<int>next;
            next.insert(num);
            for(auto it:curr){
                next.insert(it|num);
            }
            curr=next;
            res.insert(curr.begin(),curr.end());
        }
        return res.size();
    }
};