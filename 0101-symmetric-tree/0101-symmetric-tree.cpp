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
    bool solve(TreeNode* root_1,TreeNode* root_2){
        if(!root_1 && !root_2)
            return true;
        else if(!root_1 && root_2)
            return false;
        else if(root_1 && !root_2)
            return false;
        else if(root_1->val!=root_2->val){
            return false; ;
        }
        bool l_1=solve(root_1->left,root_2->right);
        bool l_2=solve(root_1->right,root_2->left);
        return (l_1 && l_2);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // left subtree root,left,right traversal is equal to right subtree root,right,left
        if(!root)
            return true;
        return solve(root->left,root->right);
    }
};