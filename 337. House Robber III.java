/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    // N = number of nodes
    // Time: O(N)
    // Space: O(N) - recursive stack
    int[] recurse(TreeNode root) {
        if(root == null)
            return new int[2];
        
        int[] left = recurse(root.left);
        int[] right = recurse(root.right);
        
        int currAndGrandchildren = root.val + left[1] + right[1];
        int children = left[0] + right[0];
        
        return new int[]{Math.max(currAndGrandchildren, children), children};
    }
    
    public int rob(TreeNode root) {
        int[] maxes = recurse(root);
        return Math.max(maxes[0], maxes[1]);
    }
}
