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
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return ;
        if(root->left==NULL && root->right==NULL)
            return;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* prev = root;
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            
            if(temp->right!=NULL) s.push(temp->right);
            if(temp->left!=NULL) s.push(temp->left);
            prev->right = temp;
            prev->left = NULL;
            prev = prev->right;
        }
    }
};