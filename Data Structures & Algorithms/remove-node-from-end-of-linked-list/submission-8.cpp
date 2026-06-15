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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int m = 0;
        while(curr != NULL){
            m++;
            curr = curr->next;
        }

        int pos = m-n+1;

        if(pos == 1){
            return head->next;
        }

        ListNode* temp1 = head;
    
        for(int i=1; i<pos-1; i++){
            temp1 = temp1->next;
        }

        
        // ListNode* temp2 = temp1->next;
        temp1->next = temp1->next->next;
        // temp2->next = NULL;

        return head;


    }
};
