class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(), stones.begin()+stones.size());
        
        while(q.size() > 1) {
            int val1 = q.top();
            q.pop();
            int val2 = q.top();
            q.pop();
            
            if(val1>val2)
                q.push(val1-val2);
        }
        
        if(q.size() == 1)
            return q.top();
            
        return 0;
    }
};
