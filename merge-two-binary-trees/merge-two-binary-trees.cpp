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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL)
            return root2;
        else if(root2==NULL)
            return root1;
        
        return merge(root1, root2);
    }
    
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return NULL;
        }
        
        if(root1!=NULL && root2!=NULL){
            root1->val = root1->val + root2->val;
            root1->left = merge(root1->left, root2->left);
            root1->right = merge(root1->right, root2->right);
            return root1;
        }
        
        if(root1==NULL && root2!=NULL){
            root2->left = merge(NULL, root2->left);
            root2->right = merge(NULL, root2->right);
            return root2;
        } 
        
            root1->left = merge(root1->left, NULL);
            root1->right = merge(root1->right, NULL);
            return root1;
        
        
    }
};