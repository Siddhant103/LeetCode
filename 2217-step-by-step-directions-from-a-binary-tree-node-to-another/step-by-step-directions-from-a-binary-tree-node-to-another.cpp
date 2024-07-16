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
    string ans = "";
    void dfs(TreeNode* root, int s, string& temp) {
        if(!root) return;
        if(root->val == s){
            ans = temp;
            return;
        }
        if(root->left)dfs(root->left, s,temp+='L');
        if(root->right)dfs(root->right,s,temp+='R');
        temp.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string temp = "";
        dfs(root,startValue, temp);
        string ls = ans;
        temp = "";
        dfs(root,destValue, temp);

        int n = ls.size();
        int m = ans.size();

        int i=0, j=0;

        string res="";

        while(i<n && j<m){
            if(ls[i] != ans[j])break;
            i++,j++;
        }

        ls.erase(0,i);
        ans.erase(0,j);

        for(int i =0; i<ls.size(); i++){
            ls[i] = 'U';
        }
        res = ls+ans;

        return res;

    }
};