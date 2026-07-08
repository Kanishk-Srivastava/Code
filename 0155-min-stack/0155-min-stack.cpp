class MinStack {
public:
    long long minVal; 
    stack<long long> st; 
    MinStack() {
        minVal = LLONG_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value); 
            minVal = value; 
        } else if(value < minVal){
            long long val = 2LL*value - minVal; 
            minVal = value; 
            st.push(val); 
        } else {
            st.push(value); 
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long topVal = st.top(); 
        if(topVal < minVal){
            long long val = 2LL*minVal - topVal; 
            st.pop(); 
            minVal = val; 
        } else {
            st.pop(); 
        }
    }
    
    int top() {
        long long topVal = st.top(); 
        if(topVal < minVal){
            return (int) minVal;
        } else {
            return (int) topVal; 
        }
    }
    
    int getMin() {
        return (int) minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */