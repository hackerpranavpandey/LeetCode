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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // so use the same concept used as the spiral matrix printing 
        // four pointer approach and simple intuition
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int top=0,bottom=m-1,left=0,right=n-1;
        while(head){
            for(int i=left;i<=right && head;i++){
                ans[top][i]=head->val;
                head=head->next;
            }
            for(int i=top+1;i<=bottom && head;i++){
                ans[i][right]=head->val;
                head=head->next;
            }
            for(int i=right-1;i>=left && head;i--){
                ans[bottom][i]=head->val;
                head=head->next;
            }
            for(int i=bottom-1;i>=top+1 && head;i--){
                ans[i][left]=head->val;
                head=head->next;
            }
            top++,bottom--,left++,right--;
        }
        return ans;
    }
};