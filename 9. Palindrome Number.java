class Solution {
    // Time: O(digits(N)), Space: O(1)
    public boolean isPalindrome(int x) {
        if(x < 0 || (x != 0 && x%10 == 0))
            return false;
        if(x < 10)
            return true;
        
        int palindrome = 0;
        while(x > palindrome) {
            palindrome = palindrome*10 + x%10;
            x /= 10;
        }
        
        return x == palindrome || x == palindrome/10;
    }
}
