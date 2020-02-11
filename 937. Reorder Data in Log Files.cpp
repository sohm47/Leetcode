class Solution {
    static bool mySort(pair<string, string> &a, pair<string, string> &b) {
        if(a.second == b.second)
            return a.first<b.first;
        return a.second<b.second;
    }
    
    
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs;
        vector<pair<string, string>> letterLogs;
        
        for(string &log: logs) {
            string identifier = "";
            int i=0; 
            while(log[i] != ' ')
                identifier.push_back(log[i++]);
            i++;
            
            if(isdigit(log[i]))
                digitLogs.push_back(log);
            else
                letterLogs.push_back({identifier, log.substr(i)});
        }
        
        sort(letterLogs.begin(), letterLogs.end(), mySort);
        
        vector<string> ans;
        for(pair<string, string> &log: letterLogs)
            ans.push_back(log.first + " " + log.second);
        for(string &log: digitLogs)
            ans.push_back(log);
        
        return ans;
    }
};
