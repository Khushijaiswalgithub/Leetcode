class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(1){
            int val=0;
            while(n>0){
                int d=n%10;
                val+=d*d;
                n=n/10;
            }
            if(val==1) return true;
            if(st.find(val)!=st.end()) return false;
            st.insert(val);
            n=val;
        }
        return true;
    }
};