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
    ListNode* rotateRight(ListNode* head, int k) {
        // same logic as rotation of array
        // first reverse entire list
        // then reverse from k to end
        // keep in mind that k can exceed the length
        // ListNode* prev=NULL;
        // ListNode* current=head;
        // int n=0;
        // while(current!=NULL){
        //     ListNode* next=current->next;
        //     current->next=prev;
        //     prev=current;
        //     current=next;
        //     n++;
        // }
        // current=prev;
        // // now reverse from k too last
        // ListNode* ans=prev;
        // k=k%n;
        // while(k>0){
        //     current=current->next;
        //     prev=prev->next;
        //     k--;
        // }
        // ListNode* temp=NULL;
        // while(current!=NULL){
        //     ListNode* next=current->next;
        //     current->next=temp;
        //     temp=current;
        //     current=next;
        // }
        // prev->next=current;
        // return prev;
        // but there is one simple way too
        // find the total length
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode* temp=head;
        int len=1;
        while(temp->next!=NULL){
            temp=temp->next;
            len++;
        }
        temp->next=head;
        k%=len;
        k=len-k;
        while(k>0){
            temp=temp->next;
            k--;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};