/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxSumPath(root, maxSum);
        return maxSum;
    }
    
    int maxSumPath(TreeNode* root, int &maxSum) {
        if (root == NULL)
            return 0;
        
        int lsum = max(maxSumPath(root->left, maxSum), 0);
        int rsum = max(maxSumPath(root->right, maxSum), 0);
        
        maxSum = max(maxSum, lsum + rsum + root->val);
        return root->val + max(lsum, rsum);
    }
};