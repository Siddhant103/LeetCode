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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans; // or take a stack and then from top put in ans vector
        if(root==NULL) 
            return ans;
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* nde=q.front();
                q.pop();
                level.push_back(nde->val);
                if(nde->left) 
                    q.push(nde->left);
                if(nde->right) 
                    q.push(nde->right);
            }
            ans.push_back(level);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};