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
    vector<int> sorted_array;
    // using this function we get the sorted array
    void Inorder(TreeNode* root){
        if(root==NULL)
            return;
        Inorder(root->left);
        sorted_array.push_back(root->val);
        Inorder(root->right);
    }
    TreeNode* constructBST(int start,int end){
        if(start>end)
            return nullptr;
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(sorted_array[mid]);
        root->left=constructBST(start,mid-1);
        root->right=constructBST(mid+1,end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        // using inorder get the sorted array
        Inorder(root);
        return constructBST(0,sorted_array.size()-1);
    }
};