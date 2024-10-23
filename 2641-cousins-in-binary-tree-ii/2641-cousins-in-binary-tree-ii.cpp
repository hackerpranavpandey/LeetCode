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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // damn its so simple just levelorder traversal and sum computation
        // first store the sum of the nodes in each of the level
        unordered_map<int,long long> levelSum;
        queue<TreeNode*> t;
        t.push(root);
        int level=0;
        while(!t.empty()){
            int n=t.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                auto it=t.front();
                t.pop();
                sum+=it->val;
                if(it->left)
                    t.push(it->left);
                if(it->right)
                    t.push(it->right);
            }
            levelSum[level]=sum;
            level++;
        }
        level=0;
        t.push(root);
        // now update the value of each node
        while(!t.empty()){
            int n=t.size();
            for(int i=0;i<n;i++){
                auto it=t.front();
                t.pop();
                if(level==0 || level==1)
                    it->val=0;
                // if both child exist then update both of them value
                if(it->left && it->right){
                    int sibling = it->left->val + it->right->val;
                    it->left->val=levelSum[level+1]- sibling;
                    it->right->val=levelSum[level+1] - sibling;
                    t.push(it->left),t.push(it->right);
                }
                // in case only left child exist
                else if(it->left && !it->right){
                    it->left->val=levelSum[level+1] - it->left->val;
                    t.push(it->left);
                }
                // in case only right child exits
                else if(!it->left && it->right){
                    it->right->val=levelSum[level+1] - it->right->val;
                    t.push(it->right);
                }
            }
            level++;
        }
        return root;
    }
};