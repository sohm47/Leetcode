class Solution {
    bool isNeighbor(string &a, string &b) {
        if(a.length() != b.length())
            return false;
        
        int count = 0;
        for(int i=0; i<a.length(); i++) {
            if(a[i] != b[i])
                if(count++ == 1)
                    return false;
        }
        
        return count == 1;
    }
    
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size() == 0)
            return 0;
        
        unordered_map<string, vector<string>> adj;
        int foundEndWord = false;
        for(string &word: wordList) {
            if(word == endWord)
                foundEndWord = true;
            if(isNeighbor(beginWord, word)) {
                adj[beginWord].push_back(word);
                adj[word].push_back(beginWord);
            }
        }
        
        if(!foundEndWord)
            return 0;
        
        for(int i=0; i<wordList.size()-1; i++) {
            for(int j=i+1; j<wordList.size(); j++) {
                if(isNeighbor(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        
        int count = 0;
        while(!q.empty()) {
            ++count;
            int size = q.size();
            for(int i=0; i<size; i++) {
                string word = q.front();
                q.pop();
                
                for(int j=0; j<adj[word].size(); j++) {
                    if(visited.find(adj[word][j]) == visited.end()) {
                        if(adj[word][j] == endWord)
                            return count+1;
                        visited.insert(adj[word][j]);
                        q.push(adj[word][j]);
                    }
                }
            }
        }
        
        return 0;
    }
};
