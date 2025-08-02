class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq;
    map<int, int> count_diff;

    for (int x : basket1) freq[x]++;
    for (int x : basket2) freq[x]--;

    vector<int> diff;
    for (auto& [val, cnt] : freq) {
        if (cnt % 2 != 0) return -1;  
        count_diff[val] = cnt / 2;
    }

    vector<int> to_swap;
    for (auto& [val, d] : count_diff) {
        for (int i = 0; i < abs(d); ++i) {
            to_swap.push_back(val);
        }
    }
    sort(to_swap.begin(), to_swap.end());
    int n = to_swap.size();
    int min_val = min(*min_element(basket1.begin(), basket1.end()),
                      *min_element(basket2.begin(), basket2.end()));

    long long cost = 0;
    for (int i = 0; i < n / 2; ++i) {
        cost += min(to_swap[i], 2 * min_val);
    }

    return cost;
        

    }
};