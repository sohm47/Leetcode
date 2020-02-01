class Solution {
    static bool mySort(vector<int> &a, vector<int> &b) {
        return a[0] < b[0];        
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)
            return {intervals[0]};
        
        vector<vector<int>> ret;
        int begin, end;
        sort(intervals.begin(), intervals.end(), mySort);
        
        for(int i=0; i<intervals.size(); i++) {
            begin = intervals[i][0];
            end = intervals[i][1];
            while(i<intervals.size() && (end>=intervals[i][1] || end>=intervals[i][0])) {
                end = max(end, intervals[i][1]);
                i+=1;
            }
            
            i -= 1;
            ret.push_back({begin, end});
        }
        
        return ret;
    }
};
