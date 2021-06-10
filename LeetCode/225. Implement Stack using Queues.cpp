class MyStack {
    queue<int> a;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        a.push(x);
        int s = a.size();
        while(s-- > 1) {
            a.push(a.front());
            a.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = a.front();
        a.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return a.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */