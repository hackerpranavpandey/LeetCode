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
    void deleteNode(ListNode* node) {
        // value update karo aur last ke node ko delete kar do
        ListNode* prev=node;
        ListNode* current=node->next;
        while(current->next!=NULL){
            prev->val=current->val;
            prev=prev->next;
            current=current->next;
        }
        prev->val=current->val;
        prev->next=NULL;
    }
};