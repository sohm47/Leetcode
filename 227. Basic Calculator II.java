class Solution {
    // Time: O(N)
    // Space: O(1)
    public int calculate(String s) {
        int result = 0, previousNumber = 0, currentNumber = 0;
        char operation = '+';
        
        for(int i=0; i<s.length(); i++) {
            char c = s.charAt(i);
            if(Character.isDigit(c)) {
                currentNumber = currentNumber*10 + Character.getNumericValue(c);
            }
            if(!Character.isDigit(c) && c != ' ' || i == s.length()-1) {
                if(operation == '+' || operation == '-') {
                    result += previousNumber;
                    previousNumber = (operation == '+' ? currentNumber : -currentNumber);
                }
                else if(operation == '*')
                    previousNumber *= currentNumber;
                else if(operation == '/')
                    previousNumber /= currentNumber;
                
                operation = c;
                currentNumber = 0;
            }
        }
        
        return result + previousNumber;
    }
}
