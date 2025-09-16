class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    stack<int> st;
    for (int num : nums) {
        int cur = num;
        while (!st.empty() && gcd(st.top(), cur) > 1) {
            cur = lcm(st.top(), cur);
            st.pop();
        }
        st.push(cur);
    }

    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }
    return ans;
}
};