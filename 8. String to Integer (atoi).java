class Solution {
    // Time: O(N), Space: O(1)
    public int myAtoi(String s) {
        int i=0;
        
        // Remove spaces
        while(i < s.length() && s.charAt(i) == ' ') { 
            i += 1;
        }
        
        // Get sign
        int sign = 1;
        if(i < s.length()) {
            if(s.charAt(i) == '-') {
                sign = -1;
                i += 1;
            }
            else if(s.charAt(i) == '+') {
                i += 1;
            }
        }
        
        // Get number
        int result = 0;
        while(i < s.length() && Character.isDigit(s.charAt(i))) {
            int add = s.charAt(i) - '0';
            
            if( result > Integer.MAX_VALUE/10 || (result == Integer.MAX_VALUE/10 && add > 7)) {
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }
            
            result = result*10 + add;
            i += 1;
        }
        
        return result*sign;
    }
}
