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
    TreeNode* reverseOddLevels(TreeNode* root) {
        // lets just go for simpe level order traversal
        // and then figure out which level to reverse and which not
        queue<TreeNode*> t;
        t.push(root);
        int level=0;
        while(!t.empty()){
            int n=t.size();
            // reverse the values here
            if(level%2==1){
                vector<int> node_values;
                for(int i=0;i<n;i++){
                    TreeNode* curr=t.front();
                    t.pop();
                    node_values.push_back(curr->val);
                    t.push(curr);
                }
                reverse(node_values.begin(),node_values.end());
                int index=0;
                for(int i=0;i<n;i++){
                    TreeNode* curr=t.front();
                    t.pop();
                    curr->val=node_values[index];
                    index++;
                    t.push(curr);
                }
            }
            // simple child insertion into the queue
            for(int i=0;i<n;i++){
                TreeNode* curr=t.front();
                t.pop();
                if(curr->left)
                    t.push(curr->left);
                if(curr->right)
                    t.push(curr->right);
            }
           level++;
        }
        return root;
    }
};