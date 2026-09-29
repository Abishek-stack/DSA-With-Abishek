class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If fast reaches NULL, remove the head
        if(fast == NULL) {
            return head->next;
        }

        // Move both pointers
        while(fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Remove the nth node from end
        slow->next = slow->next->next;

        return head;
    }
};