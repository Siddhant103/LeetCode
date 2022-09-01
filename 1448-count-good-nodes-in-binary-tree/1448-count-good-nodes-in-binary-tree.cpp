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
    int goodNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int count = 1;
        
        getCountOfGoodNodes(root->left, count, root->val);
        getCountOfGoodNodes(root->right, count, root->val);
        
        return count;
    }
    
    void getCountOfGoodNodes(TreeNode* root, int& count, int maxVal){
        if(root == NULL)
            return ;
        
        if(root->val >= maxVal){
            count++;
            getCountOfGoodNodes(root->left, count, root->val);
            getCountOfGoodNodes(root->right, count, root->val);
        } else{
            getCountOfGoodNodes(root->left, count, maxVal);
            getCountOfGoodNodes(root->right, count, maxVal);
        }
            
    }
};