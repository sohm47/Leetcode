class Solution {
public:
    void recurse(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int sum, int index) {
        if(sum == 0)
            ans.push_back(curr);
        
        for(int i=index; i<candidates.size(); i++) {
            if(i>index && candidates[i]==candidates[i-1])
                continue;
	    if(sum-candidates[i] < 0)
                break;
            curr.push_back(candidates[i]);
            recurse(candidates, ans, curr, sum-candidates[i], i+1);
            curr.pop_back();
        }
    }

    // Time: O(2^N), Space: O(N)
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        recurse(candidates, ans, curr, target, 0);
        return ans;
    }
};
