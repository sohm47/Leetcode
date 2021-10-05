class Solution {
    int[][] dp;
    
    // M = word1.length(), N = word2.length() 
    // Time: O(M*N)
    // Space: O(M*N)
    private int recurse(String word1, int m, String word2, int n) {
        if(m == word1.length() || n == word2.length())
            return Math.max(word1.length()-m, word2.length()-n);
        
        if(dp[m][n] != -1)
            return dp[m][n];
        
        int value;
        if(word1.charAt(m) == word2.charAt(n))
            value = recurse(word1, m+1, word2, n+1);
        else {
            int insert = recurse(word1, m, word2, n+1);
            int delete = recurse(word1, m+1, word2, n);
            int replace = recurse(word1, m+1, word2, n+1);
            value = 1 + Math.min(insert, Math.min(delete, replace));
        }
        
        dp[m][n] = value;
        return value;    
    }
    
    public int minDistance(String word1, String word2) {
        dp = new int[word1.length()][word2.length()];
        for(int i=0; i<word1.length(); i++)
            Arrays.fill(dp[i], -1);
        
        return recurse(word1, 0, word2, 0);
    }
