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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        // damn it's just simple level order traversal
        // vector<long long> levelSum;  // priority queue is better to use
        queue<TreeNode*> t;
        priority_queue<long long,vector<long long>,greater<long long>> levelSum;
        t.push(root);
        while(!t.empty()){
            int n=t.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=t.front();
                t.pop();
                sum+=(curr->val);
                if(curr->left)
                    t.push(curr->left);
                if(curr->right)
                    t.push(curr->right);
            }
            if(levelSum.size() < k)
                levelSum.push(sum);
            else if(levelSum.top() < sum){
                levelSum.pop();
                levelSum.push(sum);
            }
        }
        if(levelSum.size()<k)
            return -1;
        return levelSum.top();
    }
};