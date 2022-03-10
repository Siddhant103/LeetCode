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
        if(l1==NULL){
            return l2;
        } else if(l2==NULL){
            return l1;
        }
        
        ListNode* head = NULL;
        ListNode* prev;
        int sum, carry = 0;
        while(l1!=NULL || l2!=NULL){
            sum = (l1 ? l1->val:0) + (l2 ? l2->val:0) + carry;
            carry = sum>=10?1:0;
            ListNode* temp = new ListNode(sum%10);
            cout<<"SUM = "<<sum<<" CARRY = "<<carry<<endl;
            if(head == NULL){
                head = temp;
                prev = head;
            } else{
                prev->next = temp;
                prev = prev->next;
            }
            
            if(l1)
                l1=l1->next;
            if(l2)
                l2=l2->next;
        }
        
        if(carry>0){
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
            prev=prev->next;
        }
            
        return head;
    }
};