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
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }    

        ListNode* curr = head;

        while (curr->next != NULL) {
            ListNode* gcdNode = new ListNode(gcd(curr->val, curr->next->val));
            ListNode* temp = curr->next;
            curr->next = gcdNode;
            gcdNode->next = temp;
            curr = temp;
        }

        return head;
    }
};