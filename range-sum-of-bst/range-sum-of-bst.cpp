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
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        getSum(root, low, high);
        return sum;
    }
    
    void getSum(TreeNode* root, int low, int high){
        if(root==NULL)
            return;
        
        if(root->val >= low && root->val <=high){
            sum += root->val;
        }
        
        if(root->val > low){
            getSum(root->left, low, high);
        }
        if(root->val < high){
            getSum(root->right, low, high);
        }
    }
};