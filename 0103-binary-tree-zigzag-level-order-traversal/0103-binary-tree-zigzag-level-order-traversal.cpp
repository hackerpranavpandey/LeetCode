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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*> t;
        vector<vector<int>> ans;
        t.push(root);
        int level=0;
        while(!t.empty()){
            int n=t.size();
            vector<int> l;
            while(n>0){
                TreeNode* temp=t.front();
                t.pop();
                l.push_back(temp->val);
                if(temp->left)
                    t.push(temp->left);
                if(temp->right)
                    t.push(temp->right);
                n--;
            }
            if(level%2==1)
                reverse(l.begin(),l.end());
            ans.push_back(l);
            level++;
        }
        return ans;
    }
};