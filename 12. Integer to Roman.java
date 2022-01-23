class Solution {
    final static int[]  intNumbers = new int[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    final static String[] romanNumbers = new String[]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
    // Time: O(1), Space: O(1)
    public String intToRoman(int num) {
        StringBuffer roman = new StringBuffer();
        
        for(int i=0; num != 0; i++) {
            if(num >= intNumbers[i]) {
                roman.append(romanNumbers[i]);
                num -= intNumbers[i];
                
                i -= 1;
            }
        }
        
        return roman.toString();
    }
}

