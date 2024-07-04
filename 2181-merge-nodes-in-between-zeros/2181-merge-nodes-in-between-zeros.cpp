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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* current=head;
        ListNode* traverse=current->next;
        while(traverse!=NULL){
            if(traverse->val!=0)
                current->val+=traverse->val;
            else{
                // special case when traverse of next is null else will add one extra node at end
                if(traverse->next!=NULL){
                    current=current->next;
                    current->val=0;
                }
                else{
                    current->next=NULL;
                }
            }
            traverse=traverse->next;
        }
        return head;
    }
};