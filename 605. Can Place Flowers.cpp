class Solution {
public:
    // Time: O(N), Space: O(1)
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, LEN = flowerbed.size();
        for(int i=0; i<LEN; i++) {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == LEN-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                ++count;
            }
            
            if(count >= n)
                return true;
        }
        return false;
    }
};
