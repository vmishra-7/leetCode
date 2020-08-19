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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* temp = head -> next;
        if(head -> val != temp -> val) {
            head -> next = deleteDuplicates(head -> next);
            return head;
        } else {
            while(temp != NULL && head -> val == temp -> val) {
                temp = temp -> next;
            }
            return deleteDuplicates(temp);
        }
    }
};
