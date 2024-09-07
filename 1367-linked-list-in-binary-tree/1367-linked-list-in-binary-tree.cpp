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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNELLNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool check(ListNode* head,TreeNode* root){
        if(!head)
            return true;
        if(!root)
            return false;
        if(root->val==head->val)
            return (check(head->next,root->left) || check(head->next,root->right));
        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        // logic of the code is that
        // pehle level order traversal akro agar curr ka val head ke value ke barabar hai
        // tab phir recursive function ko call karo left aur right dono node ke liye
        // last me dono ka or return karo
        queue<TreeNode*> t;
        t.push(root);
        while(!t.empty()){
            int n=t.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=t.front();
                t.pop();
                if(curr->val==head->val && check(head,curr))
                    return true;
                if(curr->left)
                    t.push(curr->left);
                if(curr->right)
                    t.push(curr->right);
            }
        }
        return false;
    }
};