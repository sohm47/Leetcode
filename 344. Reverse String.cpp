class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        for(int k=0; k<s.size()/2; k++) {
            swap(s[i++], s[j--]);
        }
    }
};
