class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
    unordered_map<int, int> freq;
    long long pairCount = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); ++right) {
        pairCount += freq[nums[right]];
        freq[nums[right]]++;
        while (pairCount >= k) {
            res += (nums.size() - right);  
            pairCount -= (freq[nums[left]] - 1);  
            freq[nums[left]]--;
            left++;
        }
    }

    return res;
        
    }
};