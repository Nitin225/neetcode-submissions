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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int n = 0;

        while(temp){
            n++;
            temp = temp->next;
        }

        if(n < k) return head;

        int q = n / k;

        ListNode* curr = head;
        ListNode* prev = NULL;

        ListNode* newHead = NULL;
        ListNode* prevTail = NULL;

        int i = 0;

        while(i < q){

            ListNode* p1 = curr;   

            for(int j = 0; j < k; j++){
                ListNode* t = curr->next;
                curr->next = prev;
                prev = curr;
                curr = t;
            }

            if(newHead == NULL)
                newHead = prev;

            if(prevTail)
                prevTail->next = prev;

            prevTail = p1;

            prev = NULL;
            i++;
        }

        prevTail->next = curr;
        return newHead;
    }
};