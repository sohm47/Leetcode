class Solution {
public:
    
    // Time: O(MxN), Space: O(MxN)
    int longestCommonSubsequence(string text1, string text2) {
        int LEN1 = text1.size(), LEN2 = text2.size();
        if(LEN1*LEN2 == 0)
            return 0;
        
        vector<vector<int>> dp(LEN1+1, vector<int>(LEN2+1, 0));
        for(int i=0; i<LEN1; i++) {
            for(int j=0; j<LEN2; j++) {
                if(text1[i] == text2[j])
                    dp[i+1][j+1] = dp[i][j]+1;
                else
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        
        return dp[LEN1][LEN2];
    }
};
