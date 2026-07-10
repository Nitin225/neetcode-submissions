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
private:
    ListNode* merge(ListNode* t1, ListNode* t2){
        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(t1 != NULL && t2 != NULL){
            if(t1->val <= t2->val){
                temp->next = t1;
                t1 = t1->next;
                temp = temp->next;
                temp->next = NULL;
            }
            else{
                temp->next = t2;
                t2 = t2->next;
                temp = temp->next;
                temp->next = NULL;
            }
        }
        if(t1 == NULL)
            temp->next = t2;
        else
            temp->next = t1;

        return dummy.next;  
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode* head = lists[0];
        for(int i=1; i<n; i++){
            head = merge(head, lists[i]);
        }

        return head;
    }
};
