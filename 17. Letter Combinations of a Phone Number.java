class Solution {
    Map<Character, String> digitToLetter = Map.ofEntries(Map.entry('2', "abc"), 
                                                         Map.entry('3', "def"),
                                                         Map.entry('4', "ghi"),
                                                         Map.entry('5', "jkl"),
                                                         Map.entry('6', "mno"),
                                                         Map.entry('7', "pqrs"),
                                                         Map.entry('8', "tuv"),
                                                         Map.entry('9', "wxyz"));
    // N = length of string digits, 4 = max length of string at each digit
    // Time: O(4^N), Space: O(1) - Not counting solution space
    public List<String> letterCombinations(String digits) {
        LinkedList<String> allCombinations = new LinkedList<>();
        if(digits.isEmpty()) {
            return allCombinations;
        }
        
        allCombinations.add("");
        
        while(allCombinations.peekFirst().length() != digits.length()) {
            String currentCombination = allCombinations.removeFirst();
            int index = currentCombination.length();
            
            for(char l: digitToLetter.get(digits.charAt(index)).toCharArray()) {
                allCombinations.add(currentCombination + l);
            }
        }
        
        return allCombinations;
    }
}
