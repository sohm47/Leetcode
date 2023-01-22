class Solution {
    // Time: O(N), Space: O(1)
    public int maxProfit(int[] prices) {
        int lowestPrice = prices[0], maxProfit = 0;
        for(int price: prices) {
            maxProfit = Math.max(maxProfit, price - lowestPrice);
            lowestPrice = Math.min(lowestPrice, price);
        }

        return maxProfit;
    }
}
