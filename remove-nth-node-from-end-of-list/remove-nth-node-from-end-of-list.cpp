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
    int getSize(ListNode* head){
        int count = 0;
        
        while(head){
            count++;
            head = head->next;
        }
        
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        int nFromBegin = size - n;
        
        if(nFromBegin == 0){
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(nFromBegin--){
            prev = curr;
            curr = curr->next;
        }
        
        
        prev->next = curr->next;
        delete curr;
        return head;
    }
};