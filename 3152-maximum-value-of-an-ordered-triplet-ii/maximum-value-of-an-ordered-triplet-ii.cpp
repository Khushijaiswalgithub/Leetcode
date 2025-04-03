class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
    
    // If there are less than 3 elements, triplet is not possible.
    if (n < 3) return 0;

    vector<int> maxl(n, 0);
    vector<int> maxr(n, 0);

    maxl[0] = nums[0];
    maxr[n - 1] = nums[n - 1];

    // Calculate maximum from the left
    for (int i = 1; i < n; i++) {
        maxl[i] = max(nums[i], maxl[i - 1]);
    }

    // Calculate maximum from the right
    for (int i = n - 2; i >= 0; i--) {
        maxr[i] = max(nums[i], maxr[i + 1]);
    }

    long long maxi = 0;

    
    for (int i = 1; i < n - 1; i++) {
        if (maxl[i - 1] > nums[i] && maxr[i + 1] > 0) { 
            maxi = max(maxi, (long long)(maxl[i - 1] - nums[i]) * maxr[i + 1]);
        }
    }

    return maxi;
    }
};