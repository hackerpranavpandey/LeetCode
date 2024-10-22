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
    int maxLevelSum(TreeNode* root) {
        int ans=0;
        int sum=INT_MIN;
        queue<TreeNode*> t;
        t.push(root);
        int level=1;
        while(!t.empty()){
            int n=t.size();
            int levelSum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=t.front();
                t.pop();
                levelSum += curr->val;
                if(curr->left)
                    t.push(curr->left);
                if(curr->right)
                    t.push(curr->right);
            }
            if(levelSum > sum)
                sum=levelSum, ans=level;
            level++;
        }
        return ans;
    }
};