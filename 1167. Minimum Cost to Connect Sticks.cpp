class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if(sticks.size() == 1)
            return 0;
            
        priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
        int sum = 0;
        
        while(q.size() != 1) {
            int a=q.top();
            q.pop();
            int b = q.top();
            q.pop();
            sum += a+b;
            q.push(a+b);
        }
        
        return sum;
    }
};
