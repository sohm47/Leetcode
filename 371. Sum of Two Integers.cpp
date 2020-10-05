class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0) {
            int sum = a^b;
            b = (a&unsigned(b))<<1;
            a = sum;
        }
        return a;
    }
};
