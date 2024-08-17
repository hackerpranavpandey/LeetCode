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
private:
    void right_node_view(TreeNode* root,vector<int>& ans,int level){
        if(root==NULL)
            return;
        if(level==ans.size())
            ans.push_back(root->val);
        right_node_view(root->right,ans,level+1);
        right_node_view(root->left,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // one is simple bfs or level order traversal and pick the last element 
        // but it takes O(n) time and O(n) space
        vector<int> ans;
        right_node_view(root,ans,0);
        return ans;
    }
};