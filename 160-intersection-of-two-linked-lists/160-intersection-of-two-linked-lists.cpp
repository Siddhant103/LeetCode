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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = getSize(headA);
        int size2 = getSize(headB);
        
        int diff = abs(size1-size2);
        
        if(size1>size2){
            while(diff--)
                headA=headA->next;
        } else{
            while(diff--){
                headB=headB->next;
            }
        }
        
        while(headA!=NULL && headB!=NULL){
            if(headA==headB)
                return headB;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
    
    int getSize(ListNode* node){
        int count=0;
        while(node!=NULL){
            count++;
            node=node->next;
        }
            return count;
    }
};