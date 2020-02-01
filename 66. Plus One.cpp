class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i=digits.size()-1; i>-1 && carry!=0; i--) {
            digits[i] += carry;
            carry = digits[i]/10;
            digits[i] %= 10;
        }
        
        if(carry == 1)
            digits.insert(digits.begin(),1);
        
        return digits;
    }
};
