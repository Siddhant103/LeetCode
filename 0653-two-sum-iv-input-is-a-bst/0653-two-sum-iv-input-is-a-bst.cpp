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
    unordered_set<int> s;
    bool pairExist(TreeNode* root, int k) {
        if(root == NULL)
            return false;
        
        if(s.find(k - root->val) != s.end())
            return true;
        s.insert(root->val);
        return pairExist(root->left, k) || pairExist(root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {        
        s.clear();
        return pairExist(root, k);
    }
};