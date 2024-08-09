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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // simple merge sort concept
        if(list1==NULL)
            return list2;
        else if(list2==NULL)
            return list1;
        ListNode* temp=new ListNode();
        ListNode* ans=temp;
        ListNode* traverse_1=list1;
        ListNode* traverse_2=list2;
        if(traverse_1->val < traverse_2->val){
            temp->val=traverse_1->val;
            traverse_1=traverse_1->next;
        }
        else{
            temp->val=traverse_2->val;
            traverse_2=traverse_2->next;
        }
        while(traverse_1!=NULL && traverse_2!=NULL){
            if(traverse_1->val <= traverse_2->val){
                temp->next=traverse_1;
                traverse_1=traverse_1->next;
            }
            else{
                temp->next=traverse_2;
                traverse_2=traverse_2->next;
            }
            temp=temp->next;
        }
        while(traverse_1!=NULL){
              temp->next=traverse_1;
              traverse_1=traverse_1->next;
              temp=temp->next;
        }
        while(traverse_2!=NULL){
              temp->next=traverse_2;
              traverse_2=traverse_2->next;
              temp=temp->next;
        }
        return ans;
    }
};