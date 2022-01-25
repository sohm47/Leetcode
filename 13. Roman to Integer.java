class Solution {
    final static Map<Character, Integer> map = Map.ofEntries(Map.entry('I', 1),
                                                             Map.entry('V', 5),
                                                             Map.entry('X', 10),
                                                             Map.entry('L', 50),
                                                             Map.entry('C', 100),
                                                             Map.entry('D', 500),
                                                             Map.entry('M', 1000)
                                                            );
    
    // Time: O(N), Space: O(1)
    public int romanToInt(String s) {
        int num = 0;
        
        for(int i=0; i<s.length()-1; i++) {
            if(map.get(s.charAt(i)) < map.get(s.charAt(i+1))) {
                num -= map.get(s.charAt(i));
            }
            else {
                num += map.get(s.charAt(i));
            }
        }
        
        return num + map.get(s.charAt(s.length()-1));
    }
}
