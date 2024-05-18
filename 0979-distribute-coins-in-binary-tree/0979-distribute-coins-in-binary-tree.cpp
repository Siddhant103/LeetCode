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
    int numMoves;
public:
    int distributeCoins(TreeNode* root) {
        numMoves = 0;
        getMoves(root);
        return numMoves;
    }
    
    int getMoves(TreeNode* root){
        if(root==NULL)
            return 0;
        
        int left = getMoves(root->left);
        int right = getMoves(root->right);
        
        numMoves+= abs(left)+abs(right);
        return root->val + left + right -1;
    }
};