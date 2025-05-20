class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> tra(n, 0);  

    
    for (auto& it : queries) {
        tra[it[0]] += 1;
        if (it[1] + 1 < n) {
            tra[it[1] + 1] -= 1;
        }
    }
    
    for (int i = 1; i < n; i++) {
        tra[i] = tra[i - 1]+tra[i];
    }
    for (int i = 0; i < n; i++) {
        
        
        if (tra[i]<nums[i]) {
            return false;
        }
    }

    return true;
    }
};
