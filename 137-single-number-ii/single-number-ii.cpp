class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int res = 0;
    for (int k = 0; k < 32; k++) {
        int t = (1 << k);
        int count = 0;
        for (int n : nums) {
            if ((n & t) != 0) { 
                count++;
            }
        }
        if (count % 3 != 0) {
            res |= t;  
        }
    }
    return res;
}
};