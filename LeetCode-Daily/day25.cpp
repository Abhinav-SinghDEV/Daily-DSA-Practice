
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // Edge case: only one node
        if(head->next == NULL)
            return NULL;

        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return temp;
    }
};
