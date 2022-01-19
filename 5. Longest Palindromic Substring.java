class Solution {
    private int expandAroundCenter(String s, int left, int right) {
        while(left >=0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left -= 1;
            right += 1;
        }
        
        return right-left-1;
    }
    
    // N = length of string
    // Time: O(N^2), Space: O(1)
    public String longestPalindrome(String s) {
        int start=0, end=0;
        
        for(int i=0; i<s.length(); i++) {
            int length1 = expandAroundCenter(s, i, i);
            int length2 = expandAroundCenter(s, i, i+1);
            int maxLength = Math.max(length1, length2);
            if(maxLength > end-start) {
                start = i-(maxLength-1)/2;
                end = i+maxLength/2;
            }
        }
        
        return s.substring(start, end+1);
    }
}
