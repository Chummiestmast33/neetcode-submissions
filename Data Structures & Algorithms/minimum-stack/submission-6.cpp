class MinStack {
   public:
    stack<int> s;
    stack<int> min;
    MinStack() {}

    void push(int val) {
        // Agregar al stack de apoyo el minimo
        s.push(val);
        if (min.empty()){
            min.push(val);
        }
        else if(min.top() > val){
            min.push(val);
        }
        else{
            min.push(min.top());
        }
    }

    void pop() {
        // Eliminas el ultimo elemento del stack de apayo
        if (!s.empty()) {
            s.pop();
            min.pop();
        }
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
    // Hacer otro stack que guarde siempre el minimo XD
};
