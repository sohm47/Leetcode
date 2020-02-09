class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int i=1; i<=n; i++) {
            string s="";
            if(i%3==0)
                s = "Fizz";
            if(i%5==0)
                s += "Buzz";
            
            if(s=="")
                v.push_back(to_string(i));
            else
                v.push_back(s);    
        }
        
        return v;
    }
};
