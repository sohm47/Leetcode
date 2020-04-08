class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() < 3)
            return tree.size();
        
        int j=1;
        while(j < tree.size() && tree[j] == tree[0])
            j += 1;
        if(j == tree.size())
            return tree.size();
        
        int maxAmount = j+1;
        int firstTreeIndex = 0, firstTreeType = tree[0];
        int secondTreeIndex = j, secondTreeType = tree[j];
        for(int i=j+1; i<tree.size(); i++) {
            if(tree[i] != firstTreeType && tree[i] != secondTreeType) {
                maxAmount = max(maxAmount, i-firstTreeIndex);
                int k = i-1;
                int tempTreeType = tree[k], tempTreeIndex = secondTreeIndex;
                if(tempTreeType == firstTreeType)
                    tempTreeIndex = firstTreeIndex;
                
                while(k > tempTreeIndex && tree[k] == tempTreeType)
                    k -= 1;
                firstTreeType = tempTreeType;
                firstTreeIndex = (k == tempTreeIndex ? k : k+1);
                secondTreeType = tree[i];
                secondTreeIndex = i;
            }
        }
        
        return max(maxAmount, int(tree.size())-firstTreeIndex);
    }
};
