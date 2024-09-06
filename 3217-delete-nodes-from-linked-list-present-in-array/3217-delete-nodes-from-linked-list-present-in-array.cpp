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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> del;
        for(int num:nums){
            del.insert(num);
        }
        // dummy node in case if root node itself has to be deleted
        ListNode* ans=new ListNode(0);
        ans->next=head;
        ListNode* temp=ans;
        while(temp!=NULL){
            ListNode* next=temp->next;
            while(next!=NULL && del.find(next->val)!=del.end()){
                next=next->next;
            }
            temp->next=next;
            temp=next;
        }
        return ans->next;
    }
};