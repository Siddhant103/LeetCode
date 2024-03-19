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
    void findPath(TreeNode* root, int targetSum, vector<int> &currPath, vector<vector<int>> &result) {
        if (root == NULL) {
            return;
        }
        currPath.push_back(root->val);
        if (root->val == targetSum && root->left == NULL && root->right == NULL) {
            result.push_back(currPath);
            // return;
        }
        
        findPath(root->left, targetSum - root->val, currPath, result);
        findPath(root->right, targetSum - root->val, currPath, result);
        currPath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> currPath;
        vector<vector<int>> result;
        findPath(root, targetSum, currPath, result);
        return result;
    }
};