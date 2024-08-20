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
    void inorder(TreeNode* root,unordered_set<int>& bst_val){
        if(!root)
            return;
        else{
            bst_val.emplace(root->val);
            inorder(root->left,bst_val);
            inorder(root->right,bst_val);
        }
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> bst_val;
        inorder(root,bst_val);
        for(auto it:bst_val){
            int rem=k-it;
            if(rem!=it && bst_val.find(rem)!=bst_val.end())
                return true;
        }
        return false;
    }
};