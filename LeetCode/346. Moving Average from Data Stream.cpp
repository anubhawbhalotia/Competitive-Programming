class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue <int> q;
    int n, t = 0, s = 0;
    MovingAverage(int size) {
        n = size;
    }
    
    double next(int val) {
        q.push(val);
        t += val;
        s++;
        if(s > n)
        {
            t -= q.front();
            q.pop();
        }
        return (double)t / min(s, n);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */