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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // simple concept of storing and then reverse of array for window of size k
        vector<int> store_value;
        ListNode* temp=head;
        while(temp){
            store_value.push_back(temp->val);
            temp=temp->next;
        }
        int index=0,n=store_value.size();
        for(int i=0;i<=(n-k);i+=k){
            reverse(store_value.begin()+i,store_value.begin()+i+k);
        }
        temp=head;
        int i=0;
        while(temp){
            temp->val=store_value[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};