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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        
        if(root == NULL){
            return root;
        }
        TreeNode* curr = root, *prev = NULL;
        root = NULL;
        
        while(curr != NULL || !s.empty()){
            while(curr != NULL){
                s.push(curr);
                curr = curr->left;
            }
            
            TreeNode* temp = s.top(); s.pop();
            
            if(root == NULL)
                root = temp;
            if(prev != NULL)
                prev->right = temp;
            curr = temp->right;
            temp->left = NULL;
            prev = temp;
            
        }
        
        return root;
    }
};