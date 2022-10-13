/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp;
        //4 5 1 9
        //5
        //
        temp = node->next;  //=pointing to 1
        node->val = temp->val; // node val is 1
        node->next = temp->next;
     
        delete temp;
    }
};