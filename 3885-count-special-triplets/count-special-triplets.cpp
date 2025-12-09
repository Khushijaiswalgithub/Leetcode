class Solution {
public:
const long long MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
         unordered_map<int, long long> left, right;
        long long ans = 0;
        for(int x : nums) right[x]++;

        for(int j = 0; j < nums.size(); j++) {
            int mid = nums[j];
            right[mid]--;
            
            long long target = mid * 2;   
            
            long long leftCount = left[target];
            long long rightCount = right[target];

            ans = (ans + (leftCount * rightCount) % MOD) % MOD;

            left[mid]++; 
        }

        return ans;
    }
};