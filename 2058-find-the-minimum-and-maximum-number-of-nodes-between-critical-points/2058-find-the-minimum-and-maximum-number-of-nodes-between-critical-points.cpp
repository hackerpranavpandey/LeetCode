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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL)
            return {-1,-1};
        vector<int> pos;
        ListNode* temp=head->next;
        int prev=head->val;
        int i=1;
        while(temp!=NULL){
            // check for critical points
            int num=temp->val;
            if(temp->next!=NULL){
                if(num>prev && num>(temp->next->val)){
                    pos.push_back(i);
                }
                else if(num<prev && num<(temp->next->val)){
                    pos.push_back(i);
                }
            }
            i++;
            prev=num;
            temp=temp->next;
        }
        if(pos.size()<2)
            return {-1,-1};
        int min_dist=pos[1]-pos[0];
        for(int i=2;i<pos.size();i++){
            min_dist=min(min_dist,(pos[i]-pos[i-1]));
        }
        int max_dist=pos[pos.size()-1]-pos[0];
        return {min_dist,max_dist};
    }
};