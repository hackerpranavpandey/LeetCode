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
    int height_binary_tree(TreeNode* node){
        if(node==NULL)
            return 0;
        int left_height=1+height_binary_tree(node->left);
        int right_height=1+height_binary_tree(node->right);
        return max(left_height,right_height);
    }
public:
    int maxDepth(TreeNode* root) {
        return height_binary_tree(root);
    }
};