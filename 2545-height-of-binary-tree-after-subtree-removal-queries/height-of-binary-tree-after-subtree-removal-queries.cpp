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
    vector<int> D;
    int lvl_left = 0;
    int lvl_right = 0;
    void preorderLeft(TreeNode* root, int level){
        if (root == nullptr) return;
        D[root->val] = lvl_left;
        lvl_left = max(level,lvl_left);
        preorderLeft(root->left,level+1);
        preorderLeft(root->right,level+1);
    }
    
    void preorderRight(TreeNode* root, int level){
        if (root == nullptr) return;
        D[root->val] = max(D[root->val], lvl_right);
        lvl_right = max(level,lvl_right);
        preorderRight(root->right,level+1);
        preorderRight(root->left,level+1);
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        D.resize(100001,0);
        lvl_left = lvl_right = 0;
        preorderLeft(root,0); preorderRight(root,0);
        int sz = queries.size();
        vector<int> ans(sz,0);
        int i=0;
        for(int val : queries) {
            ans[i++] = D[val];
        }
        return ans;
    } 
};