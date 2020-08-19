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
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head -> next;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *head2 = slow -> next;
        slow -> next = NULL;
        head = sortList(head);
        head2 = sortList(head2);
        ListNode *FH = NULL;
        ListNode *FT = NULL;
        if(head -> val < head2 -> val){
            FH = head;
            FT = head;
            head = head -> next;
        } else{
            FH = head2;
            FT = head2;
            head2 = head2 -> next;
        }
        while(head != NULL && head2 != NULL){
             if(head -> val < head2 -> val){
                 FT -> next = head;
                 FT = FT -> next;
                 head = head -> next;       
             } else{
                 FT -> next = head2;
                 FT = FT -> next;
                 head2 = head2 -> next;
             }
        }
        if(head != NULL){
            FT -> next = head;    
        }
        if(head2 != NULL){
            FT -> next = head2;  
        }
        return FH;
    }
};
