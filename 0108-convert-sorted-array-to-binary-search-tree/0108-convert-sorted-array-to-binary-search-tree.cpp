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
    TreeNode* help(vector<int> &arr,int s,int e){
        if(s>e)
            return NULL;

        int m = (s + e) / 2;
        TreeNode* root = new TreeNode(arr[m]);
        root->left = help(arr, s, m-1);
        root->right = help(arr, m+1, e);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return help(nums, 0, n-1);
    }
};