class Solution {
public:
    // Time: O(N^2), Space: O(1)
    int numTeams(vector<int>& rating) {
        int count = 0;
        for(int i=0; i<rating.size(); i++) {
            int a=0, b=0, c=0, d=0;
            for(int j=0; j<rating.size(); j++) {
                if(i<j) {
                    if(rating[j]>rating[i])
                        ++a;
                    else if(rating[i]>rating[j])
                        ++c;
                }
                else if(i>j){
                    if(rating[i]>rating[j])
                        ++b;
                    else if(rating[i]<rating[j])
                        ++d;
                }
            }
            
            count += (a*b + c*d);
        }
        
        return count;
    }
};
