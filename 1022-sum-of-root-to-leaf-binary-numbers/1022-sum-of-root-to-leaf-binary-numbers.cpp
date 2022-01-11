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
    int sum = 0;
    
    void readTree(TreeNode* root, int val)
    {
        if(!root)
            return;

        val = val*2 + root->val;     // Normal Math
        //val = val << 1 | root->val;
		
        
        readTree(root->left, val);
        readTree(root->right, val);
        
        if(root->left == NULL && root->right == NULL)
            sum += val;
    }

    int sumRootToLeaf(TreeNode* root) 
    {
        readTree(root, 0);
        return sum;
    }
};