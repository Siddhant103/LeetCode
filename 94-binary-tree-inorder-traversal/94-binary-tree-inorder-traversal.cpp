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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || p != NULL){
            if(p != NULL){
                s.push(p);
                p = p->left;
            } else{
                TreeNode* temp = s.top();
                s.pop();
                result.push_back(temp->val);
                p = temp->right;
            }
        }
        
        return result;
    }
};