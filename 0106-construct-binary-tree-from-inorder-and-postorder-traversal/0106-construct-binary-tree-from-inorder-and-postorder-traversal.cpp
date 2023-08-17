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
    unordered_map<int, int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int rootIndex = postorder.size() - 1;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        
        return build(inorder, postorder, rootIndex, 0, inorder.size() - 1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& rootIndex, int left, int right){
        if(left > right)
            return NULL;
        
        int pivot = m[postorder[rootIndex]];
        rootIndex--;
        TreeNode* node = new TreeNode(inorder[pivot]);
        
        node->right = build(inorder, postorder, rootIndex, pivot + 1, right);
        node->left = build(inorder, postorder, rootIndex, left, pivot - 1);
        
        
        return node;
    }
};