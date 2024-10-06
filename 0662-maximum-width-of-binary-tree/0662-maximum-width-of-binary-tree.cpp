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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,long long>> t;
        t.push({root,0});
        while(!t.empty()){
            int n=t.size();
            long long min_ver=0,max_ver=0;
            long long mmin=t.front().second;
            for(int i=0;i<n;i++){
                auto it=t.front();
                t.pop();
                TreeNode* temp=it.first;
                long long vertical=it.second-mmin;
                if(i==0)
                    min_ver=it.second;
                if(i==n-1)
                    max_ver=it.second;
                if(temp->left){
                    t.push({temp->left,2*vertical+1});
                }
                if(temp->right){
                    t.push({temp->right,2*vertical+2});
                }
            }
            ans=max(ans,(int)(max_ver-min_ver+1));
        }
        return ans;
    }
};