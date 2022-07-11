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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> ans;
        if(root!=NULL)
            q.push(root);
        
        while(!q.empty()){
            TreeNode* temp = q.front();
            int sizeOfQ = q.size();
            for(int i=0;i<sizeOfQ;i++){
                TreeNode* temp = q.front();
                if(i==0){
                    ans.push_back(temp->val);
                }
                if(temp->right!=NULL)
                    q.push(temp->right);
                if(temp->left!=NULL)
                    q.push(temp->left);
                q.pop();
            }
        }
        return ans;
    }
};