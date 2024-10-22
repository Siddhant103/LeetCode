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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        q.push(root);
        long long sum;
        vector<long long>v;
        while(!q.empty()){
             sum=0;
            long long  n=q.size();
            for(long long i=0;i<n;i++){
                TreeNode* curnode=q.front();
                q.pop();
                sum+=curnode->val;
                if(curnode->left!=nullptr) q.push(curnode->left);
                if(curnode->right!=nullptr)q.push(curnode->right);
            }
            v.push_back(sum);
        }
        if (k > v.size() || k <= 0) {
            return -1; // Error case: k is out of range
        }
        sort(v.begin(),v.end());
        return v[v.size()-k];
    }
};