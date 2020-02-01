class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int lowest = prices[0], maxProfit = 0;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i]<lowest)
                lowest = prices[i];
            else
                maxProfit = max(maxProfit, prices[i]-lowest);
        }
        
        return maxProfit;
    }
};
