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
    int cameras;
    unordered_set<TreeNode*> visited;
public:
    void dfs(TreeNode* root, TreeNode* parent){
        if(root!=NULL){
            dfs(root->left, root);
            dfs(root->right, root);
            
            if((parent==NULL && visited.find(root)==visited.end())
              || visited.find(root->left)==visited.end() || visited.find(root->right)==visited.end()){
                cameras++;
                visited.insert(root);
                visited.insert(parent);
                visited.insert(root->left);
                visited.insert(root->right);
            }
        }
    }
    
    int minCameraCover(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        cameras = 0;
        visited.insert(NULL);
        dfs(root, NULL);
        return cameras;
    }
};