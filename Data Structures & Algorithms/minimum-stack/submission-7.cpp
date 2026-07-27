class MinStack {
private:
    stack<pair<int,int>> a;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (a.empty()) {
            a.push(make_pair(val,val));
            return;     
        }
        int minimo = min(val,a.top().second);
        a.push(make_pair(val,minimo));
    }
    
    void pop() {      
        a.pop();
    }
    
    int top() {
        return a.top().first;
    }
    
    int getMin() {
        return a.top().second;
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