/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ListNode* node = head; 
        vector<vector<int>> ans(m, vector<int>(n, -1)); 
        for (int i = 0, j = 0, di = 0, dj = 1; node; node = node->next, i+=di, j+=dj) {
            ans[i][j] = node->val; 
            if (i+di < 0 || i+di == m || j+dj < 0 || j+dj == n || ans[i+di][j+dj] != -1) 
                tie(di, dj) = make_tuple(dj, -di); 
        }
        return ans; 
    }
};