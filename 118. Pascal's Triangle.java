class Solution {
    // Time: O(N^2), Space: O(N^2)
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascalsTriangle = new ArrayList<>();
        for(int i=1; i <= numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for(int j=0; j<i; j++) {
                if(j == 0 || j == i-1) {
                    row.add(1);
                } else {
                    row.add(pascalsTriangle.get(i-2).get(j) + pascalsTriangle.get(i-2).get(j-1));
                }
            }
            pascalsTriangle.add(row);
        }

        return pascalsTriangle;
    }
}
