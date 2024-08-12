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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size_1=0,size_2=0;
        ListNode* temp=headA;
        while(temp!=NULL){
            temp=temp->next;
            size_1++;
        }
        temp=headB;
        while(temp!=NULL){
            temp=temp->next;
            size_2++;
        }
        temp=headA;
        ListNode* temp_2=headB;
        if(size_1>size_2){
            while(size_1!=size_2){
                temp=temp->next;
                size_1--;
            }
        }
        else if(size_2>size_1){
            while(size_2!=size_1){
                temp_2=temp_2->next;
                size_2--;
            }
        }
        while(temp!=NULL && temp_2!=NULL){
            if(temp==temp_2)
                return temp;
            temp=temp->next;
            temp_2=temp_2->next;
        }
        return NULL;
    }
};