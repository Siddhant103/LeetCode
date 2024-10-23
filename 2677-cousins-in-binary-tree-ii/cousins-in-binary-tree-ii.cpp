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
void updatetree(vector<int>&ls,int lev,TreeNode*root){
    if(root==NULL) return ;
    int s=0;
    if(root->left) s+=root->left->val;
    if(root->right) s+=root->right->val;
    if(root->left) root->left->val=ls[lev+1]-s;
    if(root->right) root->right->val=ls[lev+1]-s;

    updatetree(ls,lev+1,root->left);
    updatetree(ls,lev+1,root->right);
    return ;
}
    TreeNode* replaceValueInTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    root->val=0;
    vector<int> ls;
    while(!q.empty()){
        int s=0,sz=q.size();
        for(int i=0;i<sz;i++){
            auto it=q.front();
            s+=it->val;
            if(it->left){
                q.push(it->left);
            }
            if(it->right){
                q.push(it->right);
            }
            q.pop();
        }
        ls.push_back(s);
    }
    updatetree(ls,0,root);
    return root;
    }
};