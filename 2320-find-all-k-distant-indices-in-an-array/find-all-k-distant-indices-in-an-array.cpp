class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
    set<int> result;

    // Step 1: Find all indices where nums[i] == key
    for (int j = 0; j < n; ++j) {
        if (nums[j] == key) {
            // Step 2: For each such index j, add indices in range [j-k, j+k] to result
            int start = max(0, j - k);
            int end = min(n - 1, j + k);
            for (int i = start; i <= end; ++i) {
                result.insert(i);
            }
        }
    }

    // Step 3: Convert set to vector and return
    return vector<int>(result.begin(), result.end());
    }
};