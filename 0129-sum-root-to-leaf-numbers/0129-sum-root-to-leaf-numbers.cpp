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
    int sum;
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        getSumRootToLeaf(root, 0);
        return sum;
    }
    void getSumRootToLeaf(TreeNode* root, int currSum){
        if(root == NULL){
            return;
        }
        
        currSum = currSum * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            sum += currSum;
            return;
        }
        getSumRootToLeaf(root->left, currSum);
        getSumRootToLeaf(root->right, currSum);
           
    }
};