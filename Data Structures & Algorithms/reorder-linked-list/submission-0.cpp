class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        // Step 1: Find the middle
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode *prev = NULL;
        ListNode *curr = slow->next;
        slow->next = NULL;   // Split the list

        while (curr) {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Merge the two halves
        ListNode *first = head;
        ListNode *second = prev;

        while (second) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};