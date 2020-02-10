class Solution {
public:
    int fib(int N) {
        if (N==0)
            return 0;
        if (N==1)
            return 1;
        
        int a=0, b=1, c;
        for(int i = 1; i<N; i++) {
            c = a+b;
            a = b;
            b = c;
        }
        
        return c;
    }
};
