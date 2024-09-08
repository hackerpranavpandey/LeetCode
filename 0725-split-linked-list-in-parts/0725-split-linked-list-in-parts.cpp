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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // simple logic since the difference between the lenght of two cannot exceed 1 
        // so for first count%n we need to make length of count/k+count%k
        int count=0;
        ListNode* temp=head;
        while(temp){
            count++;
            temp=temp->next;
        }
        vector<ListNode*> ans(k,NULL);
        int number,buffer;
        if(k>count)
            number=1,buffer=0;
        else
            number=count/k,buffer=count%k;
        temp=head;
        count=0;
        int i=0;
        while(temp){
            ans[i]=temp,i++;
            if(count<buffer){
                for(int i=0;i<number && temp;i++){
                    temp=temp->next;
                }
            }
            else{
                for(int i=0;i<number-1 && temp;i++){
                    temp=temp->next;
                }
            }
            if(temp){
                ListNode* mid=temp->next;
                temp->next=NULL;
                temp=mid;   
            }
            count++;
        }
        return ans;
    }
};