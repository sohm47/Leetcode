class Solution {
public:
    void recurse(int &k, vector<vector<int>>& ans, vector<int>& curr, int sum, int index) {
        if(curr.size() > k)
            return;
        if(sum == 0 && curr.size() == k) {
            ans.push_back(curr);
            return;
        }
        
        for(int i=index; i<10 && sum-i>=0; i++) {
            curr.push_back(i);
            recurse(k, ans, curr, sum-i, i+1);
            curr.pop_back();
        }
    }

    // Time: O(C(9, k)), Space: O(k) 
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(n>45)
            return ans;
        
        vector<int> curr;
        recurse(k, ans, curr, n, 1);
        
        return ans;
    }
};
