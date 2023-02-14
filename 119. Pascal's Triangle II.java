class Solution {
    // Time: O(N^2), Space: O(N)
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<>(Collections.nCopies(rowIndex+1, 0));
        row.set(0, 1);
        for(int i=1; i<rowIndex+1; i++) {
            for(int j=i; j>0; j--) {
                row.set(j, row.get(j-1) + row.get(j));
            }
        }
        
        return row;
    }
}
