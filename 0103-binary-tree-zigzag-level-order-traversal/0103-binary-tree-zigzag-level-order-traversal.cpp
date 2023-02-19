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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        
        if(root == NULL)
            return result;
        
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> levelOrder(n);
            
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front(); q.pop();
                cout <<"n inside = " << n << " " <<  temp->val << endl;
                int index = (level % 2 == 0? n - 1 - i : i);
                levelOrder[index] = temp->val;
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            level++;
            result.push_back(levelOrder);
        }
        
        return result;
    }
};