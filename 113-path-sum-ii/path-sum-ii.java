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
    public void findPath(TreeNode root, int targetSum, List<Integer> currPath, List<List<Integer>> result) {
        if (root == null) {
            return;
        }
        
        currPath.add(root.val);
        if (root.val == targetSum && root.left == null && root.right == null) {
            result.add(new ArrayList<Integer>(currPath));
        }
        findPath(root.left, targetSum - root.val, currPath, result);
        findPath(root.right, targetSum - root.val, currPath, result);
        currPath.remove(currPath.size() - 1);
    }
    
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> currPath = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        findPath(root, targetSum, currPath, result);
        return result;
    }
}