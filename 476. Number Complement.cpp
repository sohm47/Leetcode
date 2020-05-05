class Solution {
public:
    // Time: O(log(num)), Space: O(1)
    int findComplement(int num) {
        if(num == 0)
            return 1;
        
        long int mask = 1;
        while(mask <= num)
            mask <<= 1;
        
        return (mask-1)^num;
    }
};
