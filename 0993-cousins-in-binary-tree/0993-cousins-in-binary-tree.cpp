/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> t;
        t.push(root);
        while(!t.empty()){
            int n=t.size();
            int find=0;
            for(int i=0;i<n;i++){
                auto it=t.front();
                t.pop();
                if(it->val==x || it->val==y)
                    find++;
                if(it->left && it->right){
                    if((it->left->val == x && it->right->val ==y) || (it->left->val == y && it->right->val ==x))
                       return false;
                    t.push(it->left);
                    t.push(it->right);
                }
                else if(it->left)
                       t.push(it->left);
                else if(it->right)
                       t.push(it->right);
            }
            if(find==2)
                return true;
        }
        return false;
    }
};