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
    bool validateBst(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }
        
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        
        return validateBst(root->left, minVal, root->val) && validateBst(root->right, root->val, maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return validateBst(root, LONG_MIN, LONG_MAX);
    }
};