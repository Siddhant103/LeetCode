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
    ListNode* getMidPoint(ListNode* head, ListNode* tail){
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=tail && fast->next!=tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return llToBST(head, NULL);
    }
    
    TreeNode* llToBST(ListNode* head, ListNode* tail){
        if(head==tail)
            return NULL;
        if(head->next==tail){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        ListNode* mid = getMidPoint(head, tail);
        TreeNode* root = new TreeNode(mid->val);
        root->left = llToBST(head, mid);
        root->right = llToBST(mid->next, tail);
        return root;
    }
};