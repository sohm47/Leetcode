class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    MedianFinder() {
        
    }
    // Time: Log(N) 
    void addNum(int num) {
        if(maxHeap.size() > minHeap.size())
            minHeap.push(num);
        else
            maxHeap.push(num);
        
        if(!maxHeap.empty() && !minHeap.empty()) {
            if(maxHeap.top() > minHeap.top()) {
                int top = minHeap.top();
                minHeap.pop();
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(top);
            }
        }
    }
   
    // Time: O(1) 
    double findMedian() {
        if(maxHeap.size() == minHeap.size())
            return (maxHeap.top()+minHeap.top())/double(2);
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
