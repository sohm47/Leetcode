class Solution {
    // Time: O(digits(N)), Space: O(1)
    public int reverse(int x) {
        int result = 0;
        
        while(x != 0) {
            int remainder = x%10, prev = result;
            result = result*10 + remainder;
            x /= 10;
            
            if((result-remainder)/10 != prev)
                return 0;
        }
        
        return result;
    }
}
