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
    // Time: O(N), Space: O(N)
    public int maxLevelSum(TreeNode root) {
        int level=1, smallestLevel=1, maxSum=root.val;
        
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        
        while(queue.size() > 0) {
            int size = queue.size(), levelSum=0;
            
            for(int i=0; i<size; i++) {
                TreeNode temp = queue.poll();
                levelSum += temp.val;
                
                if(temp.left != null)
                    queue.add(temp.left);
                if(temp.right != null)
                    queue.add(temp.right);
            }
            
            if(levelSum > maxSum) {
                maxSum = levelSum;
                smallestLevel = level;
            }
            
            level += 1;
        }
        
        return smallestLevel;
    }
}
