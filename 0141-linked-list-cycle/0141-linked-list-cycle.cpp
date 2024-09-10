/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
            return false;
        ListNode* t_1=head;
        ListNode* t_2=head;
        while(t_2!=NULL){
            if(t_2->next!=NULL)
                t_2=t_2->next->next;
            else
                return false;
            t_1=t_1->next;
            if(t_1==t_2)
                return true;
        }
        return false;
    }
};