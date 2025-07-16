#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> st; 
    vector<int> vec;

    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if (st.find(val) != st.end()) return false;
        st[val] = vec.size();  
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (st.find(val) == st.end()) return false;

        int idx = st[val];
        int last = vec.back();

        
        vec[idx] = last;
        st[last] = idx;

    
        vec.pop_back();
        st.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % vec.size(); 
        return vec[idx];
    }
};
