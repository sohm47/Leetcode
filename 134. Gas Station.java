class Solution {
    // Time: O(N)
    // Space: O(1)
    public int canCompleteCircuit(int[] gas, int[] cost) {        
        int start = 0, total = 0, tank = 0;
        for(int i=0; i<gas.length; i++) {
            tank += gas[i]-cost[i];
            if(tank < 0) {
                total += tank;
                start = i+1;
                tank = 0;
            }
        }
        
        return total+tank < 0 ? -1 : start;
    }
}
