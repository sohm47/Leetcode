class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int temp, sum;
        while(n!=1) {
            temp = n, sum = 0;
            while(temp!=0) {
                sum += ((temp%10)*(temp%10));
                temp /= 10;
            }
            
            if(s.find(sum) != s.end())
                return false;
            
            s.insert(sum);
            n = sum;
        }
        
        return true;
    }
};
