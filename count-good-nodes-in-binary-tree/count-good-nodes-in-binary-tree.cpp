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
        if(root == NULL)
            return 0;
        
        int count = 1;
        TreeNode* prev = root;
        
        getCount(root->left, count, root->val);
        cout << count << endl;
        getCount(root->right, count, root->val);
        
        return count;
    }
    
    void getCount(TreeNode* root, int &count, int maxNode){
        if(root == NULL){
            return ;
        }
        
        if(root->val >= maxNode){
            count++;
            getCount(root->left, count, root->val);
            getCount(root->right, count, root->val);
        } 
        else {
            getCount(root->left, count, maxNode);
            getCount(root->right, count, maxNode);
        }
    }
};