class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2)
            return min(cost[0], cost[1]);
        for(int i=2; i<cost.size(); i++) {
            cost[i] = cost[i]+min(cost[i-1], cost[i-2]);
        }
        
        return min(cost.back(), cost[cost.size()-2]);
    }
};
