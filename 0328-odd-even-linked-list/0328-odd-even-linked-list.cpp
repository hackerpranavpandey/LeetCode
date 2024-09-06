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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> store_value;
        ListNode* temp=head;
        int no_of_node=0;
        while(temp){
            store_value.push_back(temp->val);
            temp=temp->next;
            no_of_node++;
        }
        temp=head;
        int index=0;
        if(no_of_node%2==1){
            while(index<=no_of_node/2){
                temp->val=store_value[2*index];
                index++;
                temp=temp->next;
                }
                index=0;
            while(temp){
                temp->val=store_value[2*index+1];
                index++;
                temp=temp->next;
            }
        }
        else{
            while(index<no_of_node/2){
                temp->val=store_value[2*index];
                index++;
                temp=temp->next;
                }
            index=0;
            while(temp){
                temp->val=store_value[2*index+1];
                index++;
                temp=temp->next;
            }
        }
        return head;
    }
};