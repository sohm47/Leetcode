class Solution {
    // Time: O(N), Space: O(N)
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for(char p: s.toCharArray()) {
            if(p == '(' || p == '{' || p == '[') {
                stack.push(p);
            }
            else {
                if((stack.isEmpty()) ||
                    (p == ')' && stack.peek() != '(') ||
                    (p == ']' && stack.peek() != '[') ||
                    (p == '}' && stack.peek() != '{')) {
                return false;
                }
                
                stack.pop();
            }
        }
        
        return stack.isEmpty();
    }
}
