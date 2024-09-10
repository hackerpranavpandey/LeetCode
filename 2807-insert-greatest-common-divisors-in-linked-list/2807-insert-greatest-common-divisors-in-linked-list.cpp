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
    // need to make sure that alway n_1 is greater then n_2 then only this function works
    // using the logic of the euclidean hcf computation
    int gcd(int n_1,int n_2){
        if(n_1%n_2==0)
            return n_2;
        return gcd(n_2,n_1%n_2);
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL)
            return head;
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr){
            int n_1=max(prev->val,curr->val);
            int n_2=min(prev->val,curr->val);
            int t=gcd(n_1,n_2);
            ListNode* newNode=new ListNode(t);
            prev->next=newNode;
            newNode->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};