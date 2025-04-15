class Solution {
public:
    class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    void update(int index, int delta) {
        for (++index; index <= n; index += index & -index)
            bit[index] += delta;
    }

    int query(int index) {
        int res = 0;
        for (++index; index > 0; index -= index & -index)
            res += bit[index];
        return res;
    }

    int queryRange(int left, int right) {
        return query(right) - query(left - 1);
    }
};
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
    vector<int> pos(n);
    for (int i = 0; i < n; ++i)
        pos[nums2[i]] = i;
    vector<int> mapped(n);
    for (int i = 0; i < n; ++i)
        mapped[i] = pos[nums1[i]];
    vector<int> leftCount(n, 0);
    FenwickTree leftBIT(n);
    for (int i = 0; i < n; ++i) {
        leftCount[i] = leftBIT.query(mapped[i] - 1);
        leftBIT.update(mapped[i], 1);
    }
    vector<int> rightCount(n, 0);
    FenwickTree rightBIT(n);
    for (int i = n - 1; i >= 0; --i) {
        rightCount[i] = rightBIT.queryRange(mapped[i] + 1, n - 1);
        rightBIT.update(mapped[i], 1);
    }
    long long total = 0;
    for (int i = 0; i < n; ++i)
        total += (long long)leftCount[i] * rightCount[i];

    return total;
        
    }
};