class MinStack {
public:
    stack<long long> st; 
    long long minVal; 
    MinStack() {
        minVal = LLONG_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val); 
            minVal = val; 
        } else if(val >= minVal){
            st.push(val); 
        } else {
            st.push(2LL*val - minVal); 
            minVal = val; 
        }
    }
    
    void pop() {
        if(st.empty()) return; 

        long long topVal = st.top(); 
        st.pop(); 
        if(topVal < minVal){
            minVal = 2LL * minVal - topVal; 
        }
    }
    
    int top() {
        long long topVal = st.top(); 

        if(topVal >= minVal){
            return (int) topVal;
        } else {
            return (int) minVal; 
        }
    }
    
    int getMin() {
        return (int)minVal; 
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