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
     // only difference with height computation
     // here take max left and right subtree height for each node
    int diameter=0;
    int height(TreeNode* root){
        if(root==NULL)
            return 0;
        int l_h=height(root->left);
        int r_h=height(root->right);
        diameter=max(diameter,l_h+r_h);
        return 1+max(l_h,r_h);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h=height(root);
        return diameter;
    }
};