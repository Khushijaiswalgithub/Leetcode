class MinStack {
public:
    MinStack() {
        
    }
    stack<int>st;
    stack<int>mini;
    
    void push(int val) {
        st.push(val);
        if(mini.empty() || mini.top()>=val) mini.push(val);
        
    }
    
    void pop() {
        int val=st.top();
        if(!st.empty())st.pop();
        if(mini.top()==val){
            mini.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */