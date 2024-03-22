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
    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(head!=NULL){
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* midPoint = getMid(head);
        ListNode* reversedNode = reverseLL(midPoint);
        
        while(reversedNode!=NULL){
            if(head->val != reversedNode->val){
                return false;
            }
            head = head->next;
            reversedNode = reversedNode->next;
        }
        
        return true;
    }
};