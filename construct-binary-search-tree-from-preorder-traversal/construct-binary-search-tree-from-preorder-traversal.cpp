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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
            return NULL;
        
        TreeNode* root = NULL;
        for(int i=0;i<preorder.size();i++){
            generateBST(root, preorder[i]);
        }
        
        return root;
    }
    
    TreeNode* generateBST(TreeNode* &root, int x){
        if(root==NULL){
            root = new TreeNode(x);
            return root;
        }
        
        if(root->val > x){
            root->left = generateBST(root->left, x);
        }
        else{
            root->right = generateBST(root->right, x);
        }
        
        return root;
    }
};