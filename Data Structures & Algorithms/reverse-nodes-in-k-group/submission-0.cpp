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
        vector<int> v;
        while(temp){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int r = v.size() % k; 
        int i=0;
        vector<int> ans; 
        while(i < v.size()-r){
            for(int j=i+k-1; j>=i; j--){
                ans.push_back(v[j]);
            }
            i += k;
        }

        for(int i=v.size()-r; i<v.size(); i++){
            ans.push_back(v[i]);
        }

        ListNode* h = NULL;
        ListNode* t = NULL;

        for(int i=0; i<ans.size(); i++){
            ListNode* temp = new ListNode(ans[i]);

            if(h == NULL){
                h = temp;
                t = temp;
            }
            else{
                t->next = temp;
                t = temp;
            }
        }
        return h;
    }
};