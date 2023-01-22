// https://leetcode.com/problems/reverse-odd-levels-of-binary-tree

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
    public TreeNode reverseOddLevels(TreeNode root) {
        ArrayList<ArrayList<TreeNode> >v = new ArrayList<ArrayList<TreeNode> >();
        for (int i = 0; i < 15; i++) {
            v.add(new ArrayList<TreeNode>());
        }
        int level = 0;
        dfs(root, level, v);
        for(int i=1; i<100; i++){
            if(v.get(i).size()!=0) {
                if(i%2==1) Collections.reverse(v.get(i));
                int l = v.get(i-1).size();
                for(int k=0; k<l; k++){
                        //TreeNode p = v.at(i-1).at(k);
                        v.get(i-1).get(k).left = v.get(i).get(k*2);
                        v.get(i-1).get(k).right = v.get(i).get(k*2+1);
                }
            }
            else {
                break;
            }
        }
        return v.get(0).get(0);
    }
    public void dfs(TreeNode root, int level, ArrayList<ArrayList<TreeNode> >v){
        v.get(level).add(root);
        if(root.left!=null){
            dfs(root.left, level+1, v);
            dfs(root.right, level+1, v);
        }
    }
}