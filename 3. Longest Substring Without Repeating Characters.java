class Solution {
    // N = length of string
    // Time: O(N), Space: O(1)
    public int lengthOfLongestSubstring(String s) {
        int startIndex = -1, maxLength = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            int prevIndex = map.getOrDefault(c, -1);
            
            if(prevIndex >= startIndex)
                startIndex = prevIndex + 1;
            
            map.put(c, i);
            maxLength = Math.max(maxLength, i-startIndex+1);
        }
        
        return maxLength;
    }
}
