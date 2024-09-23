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
    ListNode* swapNodes(ListNode* head, int k) {
        // kth node from begining wale ko temp_1 point karega
        // kth node from end ko temp_2 point karega
        if(head==NULL || head->next==nullptr)
            return head;
        ListNode *temp_1=head,*temp_2=head;
        int count=1,n=0;
        while(count<k){
            temp_1=temp_1->next;
            count++;
            temp_2=temp_2->next;
            n++;
        }
        while(temp_2!=NULL){
            temp_2=temp_2->next;
            n++;
        }
        temp_2=head;
        count=1;
        int k_end=n-k+1;
        while(count<k_end){
            temp_2=temp_2->next;
            count++;
        }
        if(temp_1==temp_2)
            return head;
        temp_1->val=temp_1->val+temp_2->val;
        temp_2->val=temp_1->val-temp_2->val;
        temp_1->val=temp_1->val-temp_2->val;
        return head;
    }
};