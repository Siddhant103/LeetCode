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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        getSum(root, low, high, sum);
        return sum;
    }
    
    void getSum(TreeNode* root, int low, int high, int &sum){
        if(root==NULL)
            return;
        
        if(root->val >= low && root->val <=high){
            sum += root->val;
        }
        
        if(root->val > low){
            getSum(root->left, low, high, sum);
        }
        if(root->val < high){
            getSum(root->right, low, high, sum);
        }
    }
};
