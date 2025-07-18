class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2]; 

    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int s = nums[i] + nums[l] + nums[r];

            if (abs(target - s) < abs(target - ans)) {
                ans = s;
            }

            if (s < target) {
                l++;
            } else if (s > target) {
                r--;
            } else {
                // Exact match found
                return s;
            }
        }
    }

    return ans;
}

};