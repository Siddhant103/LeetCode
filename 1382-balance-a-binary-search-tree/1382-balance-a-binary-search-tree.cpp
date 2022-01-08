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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        return generateTree(inorder, 0, inorder.size() - 1);
    }
    
    void inOrder(TreeNode* root, vector<int> &inorder){
        if(root == NULL)
            return ;
        
        inOrder(root->left, inorder);
        inorder.push_back(root->val);
        inOrder(root->right, inorder);
    }
    
    TreeNode* generateTree(vector<int> &inorder, int left, int right){
        if(left > right){
            return NULL;
        }
        
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = generateTree(inorder, left, mid - 1);
        root->right = generateTree(inorder, mid + 1, right);
        return root;
    }
};