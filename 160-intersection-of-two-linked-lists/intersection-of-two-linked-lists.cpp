
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        if(headA == headB) {
            return headA;
        }
        ListNode *head = headA;
        while(head -> next != NULL) {
            head = head -> next;
        }
        ListNode *head1 = headB;
        while(head1 -> next != NULL) {
            head1 = head1 -> next;
        }
        if(head != head1) {
            return NULL;
        }
        head -> next = headA;
        ListNode *slow = headB;
        ListNode *fast = headB;
        while(fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) {
                cout << "YES";
                slow = headB;
                while(slow != fast) {
                    slow = slow -> next;
                    fast = fast -> next;
                }
                head -> next = NULL;
                return slow;
            }
        }
        head -> next = NULL;
        return NULL;
    }
};