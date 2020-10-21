class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int num = x^y; num != 0; num=num>>1) {
            if(num&1 == 1)
                ++count;
        }
        return count;
    }
};
