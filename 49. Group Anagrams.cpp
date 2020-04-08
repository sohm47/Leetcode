class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> anagrams;
        vector<vector<string>> ans;
        
        int index = -1;
        for(string &str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if(anagrams.find(temp) == anagrams.end()) {
                anagrams[temp] = ++index;
                ans.push_back({});
            }
            ans[anagrams[temp]].push_back(str);
        }
        
        return ans;
    }
};
