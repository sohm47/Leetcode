class Solution {
public:
    // Time: O(M+N), Space: O(126)
    int numJewelsInStones(string J, string S) {
        int arr[123] = {0};
        for(char &c: J)
            arr[c] = 1;
        
        int count = 0;
        for(char &c: S)
            count += arr[c];       
        
        return count;
    }
};
