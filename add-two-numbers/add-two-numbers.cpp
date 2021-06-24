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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL){
            return NULL;
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        
        
        ListNode *head = NULL, *curr;
        int carry = 0, sum;
        while(l1 != NULL || l2 != NULL){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            if(head == NULL){
                head = temp;
                curr = head;
            } else{
                curr->next = temp;
                curr = curr->next;
            }
            if(l1)
                l1 = l1->next;
            if(l2){
                l2 = l2->next;
            }
        }
        
        if(carry == 1){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }
        
        return head;
    }
};