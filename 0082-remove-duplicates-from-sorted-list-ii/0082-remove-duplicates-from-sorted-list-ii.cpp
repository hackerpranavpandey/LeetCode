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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int> freqCount;
        ListNode* temp=head;
        while(temp){
            freqCount[temp->val]++;
            temp=temp->next;
        }
        ListNode* ans=head;
        while(ans && freqCount[ans->val]>1){
            ans=ans->next;
        }
        if(!ans)
            return ans;
        temp=ans->next;
        ListNode* t=ans;
        t->next=NULL;
        while(temp){
            if(freqCount[temp->val]==1){
                ListNode *newNode=new ListNode(temp->val);
                t->next=newNode;
                t=t->next;
            }
            temp=temp->next;
        }
        return ans;
    }
};