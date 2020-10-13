class Solution {
public:
    void recurse(vector<int>& candidates, int index, vector<vector<int>>& ans, int sum, vector<int>& curr) {
        if(sum < 0)
            return;
        if(sum == 0)
            ans.push_back(curr);
        
        for(int i=index; i<candidates.size(); i++) {
            curr.push_back(candidates[i]);
            recurse(candidates, i, ans, sum-candidates[i], curr);
            curr.pop_back();
        }
    }

    // Time: O(N^target), Space: O(target)
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());    
	vector<vector<int>> ans;
        vector<int> curr;
	recurse(candidates, 0, ans, target, curr);
	return ans;
    }
};
