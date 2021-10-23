class Solution {
    class Trie {
        HashMap<Character, Trie> children;
        int wordLength;
        Trie() {
            children = new HashMap<>();
            wordLength = 0;
        }
    }
    // N = Number of words, K = Word length
    // Time: O(N*K)
    // Space: O(N*K)
    public int minimumLengthEncoding(String[] words) {
        Trie root = new Trie();
        HashSet<Trie> nodes = new HashSet<>();
        
        for(String word: words) {
            Trie curr = root;
            for(int i=word.length()-1; i>=0; i--) {
                curr.children.putIfAbsent(word.charAt(i), new Trie());
                curr = curr.children.get(word.charAt(i));
            }
            curr.wordLength = word.length();
            nodes.add(curr);
        }
        
        int minimumLength = 0;
        for(Trie node: nodes) {
            if(node.children.size() == 0)
                minimumLength += node.wordLength + 1;
        }
        
        return minimumLength;
    }
}
