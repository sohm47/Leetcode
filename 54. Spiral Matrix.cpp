class Solution {
public:
    // Time: O(MxN), Space: O(1)
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        
        int left=0, right=matrix[0].size(), top=0, bottom=matrix.size();
        vector<int> ans;
        while(left<right && top<bottom) {
            // left to right
            for(int i=left; i<right; i++)
                ans.push_back(matrix[top][i]);
            
            // top to bottom
            --right;
            for(int i=top+1; i<bottom; i++)
                ans.push_back(matrix[i][right]);
            
            // right to left
            --bottom;
            if(top<bottom)
                for(int i=right-1; i>left; i--)
                    ans.push_back(matrix[bottom][i]);
            
            // bottom to top
            if(left<right)
                for(int i=bottom; i>top; i--)
                    ans.push_back(matrix[i][left]);
            
            ++top, ++left;
        }
        
        return ans;
    }
};
