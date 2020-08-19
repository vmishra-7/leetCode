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
    bool isPalindrome(ListNode* head) {
        if(head == NULL) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* head2 = slow -> next;
        slow -> next = NULL;
        ListNode* cur = head2;
        ListNode* next = head2;
        ListNode* prev = NULL;
        while(cur != NULL) {
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
        head2 = prev;
        while(head2 != NULL) {
            if(head -> val != head2 -> val) {
                return false;
            }
            head = head -> next;
            head2 = head2 -> next;
        }
        return true;
    }
};
