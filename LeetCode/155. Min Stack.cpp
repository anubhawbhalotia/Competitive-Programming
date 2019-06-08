class MinStack {
public:
    /** initialize your data structure here. */
    vector <int> s, m;
    int c ;
    MinStack() {
        s.resize(10000);
        m.resize(10000);
        c = 0;
        m[0] = INT_MAX;
    }
    
    void push(int x) {
        c++;
        s[c] = x;
        m[c] = min(m[c - 1], x);
    }
    
    void pop() {
            c--;
    }
    int top() {
        return s[c];
    }
    int getMin() {
        return m[c];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */