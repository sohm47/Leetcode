class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> index(101, -1);
        for(int i=0; i<pieces.size(); i++)
            index[pieces[i][0]] = i;
        
        int i=0;
        while(i<arr.size()) {
            int k = index[arr[i]];
            if(k == -1)
                return false;
            for(int j=0; j<pieces[k].size(); j++)
                if(arr[i++] != pieces[k][j])
                    return false;
        }
        
        return true;
    }
};
