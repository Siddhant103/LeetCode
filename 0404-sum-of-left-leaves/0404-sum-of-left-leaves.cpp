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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int sum =0 ;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            if(temp->left!=NULL){
                if(temp->left->left==NULL && temp->left->right==NULL)
                    sum+=temp->left->val;
                else
                    s.push(temp->left);
            }
            if(temp->right!=NULL){
                if(temp->right->left!=NULL || temp->right->right!=NULL)
                    s.push(temp->right);
            }
        }
        
        return sum;
    }
};