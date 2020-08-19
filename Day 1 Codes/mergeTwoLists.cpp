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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) {
            return head2;
        }
        if(head2 == NULL) {
            return head1;
        }
        if(head1 == NULL && head2 == NULL) {
            return NULL;
        }
        ListNode* FH = NULL;
        ListNode* FT = NULL;
        if(head1 -> val < head2 -> val) {
            FH = head1;
            FT = head1;
            head1 = head1 -> next;
        } else {
            FH = head2;
            FT = head2;
            head2 = head2 -> next;
        }
        while(head1 != NULL && head2 != NULL) {
            if(head1 -> val < head2 -> val) {
                FT -> next = head1;
                FT = head1;
                head1 = head1 -> next;
            } else {
                FT -> next = head2;
                FT = head2;
                head2 = head2 -> next;
            }
        }
        if(head1 != NULL) {
            FT -> next = head1;

        }
        if(head2 != NULL) {
            FT -> next = head2;
        }
        return FH;
        }
};
