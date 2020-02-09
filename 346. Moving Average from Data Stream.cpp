class MovingAverage {
public:
    /** Initialize your data structure here. */
    queue<double> q;
    double sum; 
    int windowSize;
    
    MovingAverage(int size) {
        windowSize=size;
        sum=0;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if(q.size()>windowSize) {
            sum -= q.front();
            q.pop();
        }
        
        return sum/double(q.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
