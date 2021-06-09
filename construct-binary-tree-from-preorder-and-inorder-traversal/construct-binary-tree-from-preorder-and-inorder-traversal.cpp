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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0){
            return NULL;
        }
        
        int rootIndex = 0;
        
        return build(preorder, inorder, rootIndex, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIndex, int left, int right){
        if(left > right)
            return NULL;
        int indexInOrder = left;
        while(inorder[indexInOrder] != preorder[rootIndex])
            indexInOrder++;
        
        rootIndex++;
        TreeNode* node = new TreeNode(inorder[indexInOrder]);
        node->left = build(preorder, inorder, rootIndex, left, indexInOrder - 1);
        node->right = build(preorder, inorder, rootIndex, indexInOrder + 1, right);
        return node;
    }
};