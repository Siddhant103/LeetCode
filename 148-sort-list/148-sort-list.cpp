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
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        
        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(slow);
        
        return merge(leftSorted, rightSorted);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* temp = new ListNode(0);
        ListNode* current = temp;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                current->next = l1;
                l1=l1->next;
            } else{
                current->next = l2;
                l2=l2->next;
            }
            current=current->next;
        }
        while(l1!=NULL){
            current->next=l1;
            l1=l1->next;
            current=current->next;
        }
        while(l2!=NULL){
            current->next=l2;
            l2=l2->next;
            current=current->next;
        }
        
        return temp->next;
    }
};