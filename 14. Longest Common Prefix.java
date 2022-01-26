class Solution {
    // M = Number of strings, N = Max length of string
    // Time: O(M*N), Space: O(1)
    public String longestCommonPrefix(String[] strs) {
        for(int i=0; i<strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for(int j=0; j<strs.length; j++) {
                if(i == strs[j].length() || strs[j].charAt(i) != c)
                    return strs[0].substring(0, i);
            }
        }
        
        return strs[0];
    }
}
