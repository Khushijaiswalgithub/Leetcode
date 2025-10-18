class Solution {
public:
   int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    long long nextFree = LLONG_MIN / 2; 
    int count = 0;

    for (long long num : nums) {
        long long start = num - k;
        long long end = num + k;
        if (nextFree < start)
            nextFree = start;
        if (nextFree <= end) {
            count++;
            nextFree++;
        }
    }
    return count;
}

};