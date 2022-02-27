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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        queue<pair<TreeNode*, unsigned long long int>> q;
        q.push({root, 1});
        int ans = 0, size = 0, d;
        
        while(!q.empty() ){
            size = q.size();
            if (size == 1){
                q.push({q.front().first,1});
                q.pop();
            }
            d = q.back().second-q.front().second+1;
            ans = max(ans,d);
            while(size--){
                if(q.front().first->left) 
                    q.push({q.front().first->left,(q.front().second*2)});
                if(q.front().first->right) 
                    q.push({q.front().first->right,((q.front().second*2)+1)});
                q.pop();
            }
        }
        
        return ans;
    }
};