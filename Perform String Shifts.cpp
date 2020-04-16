class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total=0;
        for(int i=0; i<shift.size(); i++) {
            if(shift[i][0] == 1)
                total += shift[i][1];
            else
                total -= shift[i][1];
        }
        
        total %= int(s.length());
        if(total == 0)
            return s;
        
        string newString = "";
        if(total<0)
            newString = s.substr(abs(total))+s.substr(0, abs(total));
        else
            newString = s.substr(s.length()-total) + s.substr(0, s.length()-total);
            
        return newString;
    }
};
