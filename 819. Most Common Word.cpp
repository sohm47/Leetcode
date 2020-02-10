class Solution {
    static bool mySort(pair<string, int> &a, pair<string, int> &b) {
        return a.second>b.second;
    }
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> m;
        for(int i=0; i<paragraph.length(); i++) {
            string temp = "";
            while(i!=paragraph.length() && isalpha(paragraph[i]))
                temp.push_back(tolower(paragraph[i++]));
            if(bannedSet.find(temp) == bannedSet.end())
                m[temp] += 1;
            
            while(i!=paragraph.length() && !isalpha(paragraph[i])) 
                i += 1;
            i -= 1;
        }
        
        vector<pair<string, int>> words;
        for(auto &p: m)
            words.push_back({p.first, p.second});
        sort(words.begin(), words.end(), mySort);
        
        return words[0].first;
    }
};
