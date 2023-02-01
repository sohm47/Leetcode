class Solution {
    // Time: O(N), Space: O(1)
    public int[] countBits(int n) {
        int[] ans = new int[n+1];
        int highestPowerOfTwo = 1;
        for(int i=1; i <= n; i++) {
            if(highestPowerOfTwo * 2 == i) {
                highestPowerOfTwo *= 2;
            }

            ans[i] = ans[i - highestPowerOfTwo] + 1;
        }

        return ans;
    }
}
